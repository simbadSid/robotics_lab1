// markov_localization.c : lab on markov_localization
//
#include <stdio.h>

#define nb_state 20
#define nb_action 1
#define nb_observation 2
#define wall 0
#define door 1

float current_localization[nb_state]; // used to store the current probability distribution over the states. You have to use it to store the results of prediction.
float previous_localization[nb_state]; // used to store the previous probability distribution over the states. You have to use to perform prediction.
float dynamic_tab[nb_state+1][nb_action+1];
float sensor_tab[nb_observation][nb_observation];
int map_left[nb_state];
int map_right[nb_state];

void init_position(int position) {
// if position == 0 then unknown initial position
// otherwise the initial position is "position"
// we store the initial position in previous_localization

	int current_state;

}// init_position

float dynamic_model(int current_state, int previous_state, int action) {
//return the probability to reach the state "current_state" from the state "previous_state" performing the action "action": P(S(t+1) = current_state | S(t) = previous_state, A(t) = action)

	int loop, loop2;

	for( loop = 0; loop < nb_state; loop++ )
		for( loop2 = 0; loop2 < nb_action; loop2++ )
			dynamic_tab[loop][loop2] = 0;

	//store a first sensor model: a perfect dynamic model
	dynamic_tab[1][1] = 1;//P(S_t = s + 1 | S_(t-1) = s, A = 1 ) = 100%
	
	//store a second sensor model
	//dynamic_tab[1][1] = 0.90;//P(S_t = s + 1 | S_(t-1) = s, A = 1 ) = 90%
	//dynamic_tab[0][1] = 0.05;//P(S_t = s | S_(t-1) = s, A = 1 ) = 5%
	//dynamic_tab[2][1] = 0.05;//P(S_t = s+2 | S_(t-1) = s, A = 1 ) = 5%

	//store a third sensor model
	//dynamic_tab[1][1] = 0.8;//P(S_t = s + 1 | S_(t-1) = s, A = 1 ) = 80%
	//dynamic_tab[0][1] = 0.1;//P(S_t = s | S_(t-1) = s, A = 1 ) = 10%
	//dynamic_tab[2][1] = 0.1;//P(S_t = s  + 2| S_(t-1) = s, A = 1 ) = 10%

	return( dynamic_tab[current_state-previous_state][action] );

}// dynamic_model

float sensor_model(int observation, int current_state) {
// return the probability to observe "observation" when we are located in the state "current_state": P(O(t) = observation | S(t) = current_state)

	//store a first sensor model: a perfect sensor model
	sensor_tab[door][door] = 1;
	sensor_tab[wall][door] = 0;
	sensor_tab[wall][wall] = 1;
	sensor_tab[door][wall] = 0;

	//store a second sensor model
	//sensor_tab[door][door] = 0.8;
	//sensor_tab[wall][door] = 0.2;

	//sensor_tab[wall][wall] = 0.7;
	//sensor_tab[door][wall] = 0.3;
	
	return( sensor_tab[observation][map_left[current_state]] );

}// sensor_model

//float sensor_model(int left_observation, int right_observation, int current_state) {
// the two observations are independent

//}// sensor_model

void store_map() {

	// store the map
	int loop;
	for( loop = 0; loop < nb_state; loop++ )
{
		map_left[loop] = wall;
		map_right[loop] = wall;
	}
		
	map_left[5] = door;
	map_left[9] = door;
	map_left[13] = door;
	
	map_right[2] = door;
	map_right[3] = door;
	map_right[7] = door;
	map_right[9] = door;
	map_right[11] = door;
	map_right[17] = door;
		
}// store_map

void prediction(int action) {

	int current_state, previous_state;
	
	//prediction

}// prediction

void estimation(int observation) {
// we use the previous_localization to do the prediction
// and store the results in the current_localization

	int current_state;
	
	//estimation: confrontation between prediction and observation

}// estimation

void normalization() {
// we normalize current_localization
// and copy it in previous_localization for the next step

	int current_state;

	//normalization
	float norm = 0;
	
	//copy of current_localization in previous_localization

}//normalization

void display() {
//we display the current_localization

	int current_state;
	float sum = 0;

	for( current_state = 0; current_state < nb_state; current_state++ )
{
		printf("P(S_t = %d) = %f\n", current_state+1, current_localization[current_state]);
		sum += current_localization[current_state];
	}
	printf("somme = %f\n");
	printf("\n");

}// display

//****************************************************
// main
//****************************************************

int main(int argc, char* argv[]) {

	store_map();
	init_position(1);
	display();

	printf("prediction\n");
	prediction(1);// we move from one meter to the right
	/*display();
	printf("estimation\n");
	estimation(wall);*/
	normalization();
	display();
	  
	printf("prediction\n");
	prediction(1);// we move from one meter to the right
	/*display();
	printf("estimation\n");
	estimation(wall);*/
	normalization();
	display();
	
	printf("prediction\n");
	prediction(1);// we move from one meter to the right
	/*display();
	printf("estimation\n");
	estimation(wall);*/
	normalization();
	display();
	
	printf("prediction\n");
	prediction(1);// we move from one meter to the right
	/*display();
	printf("estimation\n");
	estimation(wall);*/
	normalization();
	display();
	
	printf("prediction\n");
	prediction(1);// we move from one meter to the right
	/*display();
	printf("estimation\n");
	estimation(wall);*/
	normalization();
	display();
	
	return 0;

}// main
