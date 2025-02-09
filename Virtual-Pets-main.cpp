/**
  L3: Virtual Pets
  By Logan Anglin

  Starter code by Dr. Jan Pearce to explore classes, arrays, and pseudo-randomness
  Created for CSC 236 Data Structures at Berea College
 */

#include <iostream> //for input & output
#include <random> //needed for Getrandom

using namespace std;

class GetRandom {
	/** Uses <random> from C++11 to return a random integer in range [1..size] */
public:
	GetRandom(int size) {
		random_device rd; // declares a random_device object that need to generate a random number.
		mt19937 gen(rd()); //mt19937 is an efficient pseudo-random number generator using the Mersenne twister algorithm.
		uniform_int_distribution<int> intdist(1, size); //create a uniform distribution object to turn the pseudorandom result into a random digit between 1 and size.
		self_rand_int_ = intdist(gen); //generates the random number.
	}
	int roll() {
		return self_rand_int_;
	}
private:
	int self_rand_int_;
}; // end of GetRandom

class Dice {
	/** class that can be used to make dice.
	Dependent upon the Getrandom class above. */
public:
	Dice() {// default constructor assumes a 6-sided die.
		self_roll_count_ = 0;
		self_sides_ = 6;
	}
	Dice(int sides) {        // constructor for any size dice
		self_roll_count_ = 0;
		self_sides_ = sides;
	}
	int roll() {             // return the random roll of the die
		// postcondition: number of rolls updated, random 'die' roll returned

		GetRandom newrandom(self_sides_);
		self_roll_count_ = self_roll_count_ + 1;         // update # of times die rolled
		return(newrandom.roll());
	}
	int get_sides() const {   // how many sides this die has
		// postcondition: return # of sides of die
		return self_sides_;
	}
	int get_roll_count() const {   // # times this die rolled
		// postcondition: return # of times die has been rolled
		return self_roll_count_;
	}
private:
	int self_roll_count_;       // # times die rolled
	int self_sides_;           // # sides on die
}; // end of Dice - a semi colon must end every C++ class declaration.


//---------------------------------------------------------------------

class Horse {
public:
	Horse(string horse_name, int horse_age) {
		/** Creates a horse object. It is given a name and age, and the rest of the horse's attributes are calculated based on the horse's
		age.*/
		name = horse_name;
		age = horse_age;
		energy_level = 600 - (age * 3);
		speed = 0;
		top_speed = 70 - age;
		dist_from_end = 300;
	}
	void moveForward(int horse_jockey_weight) {
		/**Moves the horse forward, and calls the method that depletes the horse's energy. */
		depleteEnergyLevel(horse_jockey_weight);
		dist_from_end = dist_from_end - speed;
		if (dist_from_end <= 0) {
			cout << "You have crossed the finish line!" << endl;
		}
		else {
			cout << "Your speed is " << speed << "." << endl;
			cout << "You are currently " << dist_from_end << " meters from the finish line." << endl;
		}
	}
	void depleteEnergyLevel(int energy_level_weight) {
		/**Lowers the horse's energy level each turn. The horse will become exhausted and not be able to run any longer if the energy
		level hits 0.*/
		GetRandom newrandom(30); // Creates a random integer for some added randomness to the energy level.
		energy_level = energy_level - (energy_level_weight / 2) - speed - (newrandom.roll());
		cout << "Energy level: " << energy_level << endl;
		if (energy_level <= 0) {
			is_exhausted = true;
		}
	}

	int getSpeed() {
		return speed;
	}

	void setSpeed(int in_speed) {
		speed = in_speed;
	}
	int getAge() {
		return age;
	}
	int getTopSpeed() {
		return top_speed;
	}

	int getDistance() {
		return dist_from_end;
	}
	bool getIsExhausted() {
		return is_exhausted;
	}

private:
	string name;
	int age; // between 1 and 10
	int speed;
	int top_speed;
	int energy_level;
	int dist_from_end;
	bool is_exhausted = false;
};

class Jockey {
public:
	Jockey(string jockey_name, int jockey_weight, int jockey_exp_level) {
		/**Creates the Jockey object. The name, weight, and experience level are all given.*/
		name = jockey_name;
		weight = jockey_weight; // between 30 - 100
		exp_level = jockey_exp_level; // between 1-5
	}
	void startHorse(Horse& horse) {
		/**Used for initially getting the horse moving. Interacts with a horse object by controlling its speed.*/
		int jockey_speed = horse.getSpeed();
		int jockey_horse_age = horse.getAge();
		int jockey_horse_top_speed = horse.getTopSpeed();
		jockey_speed = jockey_horse_top_speed - (jockey_horse_age * 2) - ((5 - exp_level) * 2);
		horse.setSpeed(jockey_speed);
	}
	void increaseSpeed(Horse& horse) {
		/**Increases the speed of a horse object.*/
		int jockey_speed = horse.getSpeed();
		int jockey_horse_top_speed = horse.getTopSpeed();

		jockey_speed = jockey_speed + (exp_level * 3);
		if (jockey_speed >= jockey_horse_top_speed) {
			horse.setSpeed(jockey_horse_top_speed);
			cout << "Horse is at top speed!" << endl;
		}
		else {
			horse.setSpeed(jockey_speed);
		}
	}
	void decreaseSpeed(Horse& horse) {
		/**Decreases the speed of a horse object.*/
		int jockey_speed = horse.getSpeed();
		int jockey_horse_top_speed = horse.getTopSpeed();

		jockey_speed = jockey_speed - (exp_level * 3);

		horse.setSpeed(jockey_speed);
	}
	int getWeight() {
		return weight;
	}

private:
	string name;
	int weight;
	int exp_level;
};

// main begins here

int main() {

	char stopme;
	char selection;

	Horse myHorse("Jerry", 6);

	Jockey myJockey("Logan", 80, 3);

	myJockey.startHorse(myHorse);
	cout << "At the start of the race, your horse starts moving with " << myHorse.getSpeed() << " speed.";

	cout << endl;

	while (myHorse.getDistance() > 0) { // While the horse has not crossed the finish line.
		if (!myHorse.getIsExhausted()) { // Will stop the race if the horse becomes exhausted.
			int jockey_weight = myJockey.getWeight();

			//The next block of code uses the jockey object to control the speed of the horse object.
			int speed_manipulator;
			cout << "Press 1 to increase speed, 0 to decrease speed, or any other key to remain at the same speed." << endl;
			cin >> speed_manipulator;
			if (speed_manipulator == 1) {
				myJockey.increaseSpeed(myHorse);
			}
			else if (speed_manipulator == 0) {
				myJockey.decreaseSpeed(myHorse);
			}

			// Moves the horse forward each turn.
			myHorse.moveForward(jockey_weight);
		}
		else {
			cout << "The horse ran out of energy." << endl;
			break;
		}
	}

	cin >> stopme; //holds open the window in some cases
	return 0;
}



