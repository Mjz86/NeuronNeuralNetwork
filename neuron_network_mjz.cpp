
// credit to Pranavgulati for the original library https://github.com/Pranavgulati/neuralDuino
class Neuron_network {

public:

    
    
     uint8_t  tick_activation_of_neuron (int index_of_neuron  ); 
      /*
     calculate  the output 
     move the output  to the cal_output 
      return 0
     */
     uint8_t  tick_deactivation_of_neuron (int index_of_neuron  ); 
      /*
      move cal_output  to output
     */
     uint8_t  calculate_input_to_output (int index_of_neuron); 
      /*
     get input and make them inside  of the min and max output/input range 
     use the activation function to get the output
     */
     uint8_t  getOutput (float *  input_array ,  float * output_array  , int tick_num ); 
      /*
     inside of  this library there is 2 types  of general  networks  
     1.non real time 
     2.with real time     
     and here is the non real time function 
     copy the input array  to all_input then  you feed it into the (type_i_am == is_input) neurons  base on their index_in_type  
     tick all neurons  for tick_num times 
     move output from the (type_i_am == is_output) neurons  base on their index_in_type   to the  output_array
     then you delete all unnecessary  data
   */
     uint8_t  tick_for_all(int tick_num); 
      /*
     use tick_activation_of_neuron  for all neurons  and
     use tick_deactivation_of_neuron  for all neurons  
     for tick_num times 
     
     */
     uint8_t  tick_for_all(float *input ,   int tick_num); 
      /* copy the input array  to all_input then  you feed it into the (type_i_am == is_input) neurons  base on their index_in_type  
      
     use tick_activation_of_neuron  for all neurons  and
     use tick_deactivation_of_neuron  for all neurons  
     for tick_num times 
     
     */
     uint8_t  get_output_for_all (float **pointer_to_output ); 
      /*
       move output from the (type_i_am == is_output) neurons  base on their index_in_type   to the  output_array
     
     */
     uint8_t  learn (float * input ,float *output ); 
      /*
       copy the input array  to all_input then  you feed it into the (type_i_am == is_input) neurons  base on their index_in_type  
       tick for normal_tick times      then you  compere the outputs and use the delta  for backpropagation 
       then tou adjuste the weights  and  again tick 
       
     */
     uint8_t  learn (training_data data ); 
      /*
       copy the input array  to all_input then  you feed it into the (type_i_am == is_input) neurons  base on their index_in_type  
       tick for normal_tick times      then you  compere the outputs and use the delta  for backpropagation 
       then tou adjuste the weights  and  again tick 
       
     */
     uint8_t  learn (float **input ,float **output ,int num_of_data, int num_of_iterations); 
      /*
     you use the learn function  to  learn all the array  for num_of_data times
     
     */
      uint8_t  learn (training_data *data ,int num_of_data, int num_of_iterations); 
      /*
     you use the learn function  to  learn all the array  for num_of_data times
     
     */
     uint8_t  setup_NN (int  neuron_number); //need random seed
      /*
     use random weites and setup the network 
     */
       uint8_t  setup_neuron (int index_of_neuron,int index_in_type , int type_of_neuron, int num_syn); 
      /*
     set the index for the neuron
     set the type of neuron     
     set the number of synapase
    */
     uint8_t  setup_NN (int  neuron_number,neuron_data **neurons); 
      /*
     setup the neurons  based on the data 
     and use the data given  for the functions          
     */
     uint8_t  connect_neuron_input (int index_main ,int index_connected_to); 
      /*
     connects the input of main to the output of connected_to 
     (gets the pointer from main and stores it and adds a new neuron to the list)    
     */
     uint8_t  bias_the_neuron_int (int index_main ,float output ); 
      /*
     makes a  bias neuron send a specific  output 
    */
     uint8_t  activation_neuron_function( int index_of_neuron , activFn userFn);
      /*
     set the ActivationFn  for a neuron  
     
     */
    
    float    learning_rate ;
    float    min_input;
      /*
     minimum amount of input  for a neuron 
     */
    float    max_input;
      /*
    maximum amount of input  for a neuron 
     */
    float  normal_tick_factor ;
    int  normal_tick_times ;
      /*
normal_tick_times = (normal_tick_factor × number_of_neuron²  ÷ number_of_synapase ) +(normal_tick_factor  * number_of_neuron ) ;
     */
    bool A_settings[32];
    uint32_t settings ;
      /*
     0 is real time
     1 update the output  after tick_activation_of_neuron
     2 add randomly added weights  to the backpropagation weights 
     3 use backpropagation 
     4 is from memory 
     5 use error² / use abs of error 
     6 display  error 
     7 display  debug
     8 debug
     9 is dev
     10  halt  when  error 
     11  for min max ovf : use sine for getting output or input / use min or max for getting output or input 
     12 consider  ovf of min max a error 
     13 how to  use memory bit 0 (not implemented yet if you have ideas put them in the issue)
     14 how to  use memory bit 1 (not implemented yet if you have ideas put them in the issue)
     15 how to  use memory bit 2 (not implemented yet if you have ideas put them in the issue)
     16 how to  use memory bit 3 (not implemented yet if you have ideas put them in the issue)
     17 how to  use memory bit 4 (not implemented yet if you have ideas put them in the issue)
     18 how to  use memory bit 5 (not implemented yet if you have ideas put them in the issue)
     19 how to  use memory bit 6 (not implemented yet if you have ideas put them in the issue)
     20 how to  use memory bit 7 (not implemented yet if you have ideas put them in the issue)
     21(not implemented yet if you have ideas put them in the issue)
     22(not implemented yet if you have ideas put them in the issue)
     23(not implemented yet if you have ideas put them in the issue)
     24(not implemented yet if you have ideas put them in the issue)
     25(not implemented yet if you have ideas put them in the issue)
     26(not implemented yet if you have ideas put them in the issue)
     27(not implemented yet if you have ideas put them in the issue)
     28(not implemented yet if you have ideas put them in the issue)
     29(not implemented yet if you have ideas put them in the issue)
     30(not implemented yet if you have ideas put them in the issue)
     31(not implemented yet if you have ideas put them in the issue)

     */
  
    struct training_data{
float *input ;
      /*
     the input array  with the input data 
     
     */
float *output ;
      /*
     the output answer array with the output answers
     
     */
int tick_for_train ;
      /*
     number of tickets  in this  training course 
     
     */
};
private:
    bool was_random ;//is_active , from_memory ;
      /*
    needed for  the non memory  setup 
     
     */
    uint32_t tick_left; 
      /*
     number of ticks that  is left  before  going  to halt
     
     */
    uint8_t error; 
      /*
     the error  that  happened goes to this var
     
     */
    int num_of_all_Synapse ;
      /* for calculating the normal tick
     */
    int num_of_all_neurons ;
      /* for calculating the normal tick
     */
    float    *all_input ;
      /* 
       has   the input for each  input neuron based on their index_in_type 
     
     */
    float    *all_output;
      /*
       has   the output for each  output neuron based on their index_in_type 
     
     */
    float    *inputXweights ; //shod be in function 
      /*
     input × weights  array  for calculation 
     
     */
    float    * input_number_array;//shod be in function 
      /*
      array of input numbers for calculation 
     
     */
     /* not mine*/
/*
	to prevent memory fragmentation while retaining flexibility the begin function
	allocates memory one time only, while it is possible to do away with this
	and have completely dynamic allocn and reallocn but it is not advisable because the RAM may get
	fragmented

	ARGs:
	noConnections : implies that this neuron will not have any connections coming into it
                    when noConnections = HIGH, this doesnt allocate memory for the same
	noInputs	  : implies that this neuron will not have any float inputs coming into it from the user
                    when noInputs = HIGH, this doesnt allocate memory for the same
	these are optional arguments for those people who know what they are doing 
	*/
     uint8_t begin( int index_of_neuron , int num_syn, int noConnections = FALSE, int noInputs = FALSE);
	/*
	adjust weights according to the update rule
	*/
	uint8_t adjWeights( int index_of_neuron );
	/*
	backpropagate the betas to the connected nodes only
	*/
	uint8_t backpropagate( int index_of_neuron , int tick );
	/*
	setDesiredOUtput only valid for the last nodes
	*/
	uint8_t setDesiredOutput( int index_of_neuron , float desiredOutput);
	/*
	Set the constant input values for the input layer
	*/
	uint8_t setInput( int index_of_neuron , float input[]);
	uint8_t setInput( int index_of_neuron , int input[]);
	/*
	Set the constant output value mostly for the bias node only
	*/
	uint8_t setOutput( int index_of_neuron , int value);
	/*
	print the final weights after learning has happened
	*/
	//uint8_t printWeights( int index_of_neuron );
	/*
	connect other nodes to this->node as inputs
	this function accepts one neuron pointer and adds to the
	list of input pointer from which output is taken as an input for this node
	*/
	uint8_t connectInput( int index_of_neuron , neuron* inNode);
	/*
	get output from the input nodes	
	*/
	uint8_t getOutput( int index_of_neuron, float *output);
	/*
	set the activation functionfor this->node
	*/
	uint8_t setActivationFn( int index_of_neuron , activFn userFn);
    
    
 typedef float (*activFn)(*float,*float,uint8_t,*uint8_t);
 /* pointer to
activation function  with (input_array,weights,high_or_low ,  pointer_to_error )

 */
struct neuron_data {
  /*
	synWeight holds the weight of each synapase that is INCOMING for that neuron
	the length of synWeight is decided by the begin() function where mem alloc 
	takes place.
	*/
	float *synWeight;
	float *newWeights;
	/*stores the previous change ini weight for each synapse, ONLY required for 
	momentum functionality
	*/
	float *prevDelWeight;
	/*
	for a neuron to which no other neurons are connected an input may be specified
	this implies that neuron will have inputs defined by the user instead of being 
	the output of other neurons
	*/
	float *input;
	/*
	the second way to have inputs is to have output of some other neurons feed into 
	this neuron inNodes stores the address of every neuron which is connected to this
	neuron and asks for the output from each of those to calculate its output
	*/
	neuron_data **inNodes ; //array of pointers of type neuron
	/*
	stores the output of this neuron
	*/
	float cal_output = 0;
	//float desierd_output = 0; 
	float output = 0; 
	// float newoutput = 0; 
	/*
	counts the number of neurons that are connected to this neuron using connectInput(); 
 	be advised this DOES NOT keep count of the inputs specified
	by the programmer by the setInput() function
	*/
	int inCap = 0 ;
	int inCount = 0 ; //input Nodes are only counted 
	/*
	keeps count of the inputs specified by setInput() and begin(); 
 	this counts the number of float array type inputs and not the connectInput() ones
	*/
	int numSynapse = 0 ;
	/*
	associates an activation function for this neuron, user sets the address of any activation 
	function using setActivationFn(); 
 	*/
	activFn activation;
	float beta = 0 ; //just another backpropagation constant
	uint8_t type_i_am ; // is_bias1 is_input2 is_output3 is_hidden4 is_garbage 4<X
	int index_in_type ;
	int index_in_net ;
	
};
}