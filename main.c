#include<stdio.h>
#include<stdlib.h>

double rand_float(void){
    return (double) rand()/ (double) RAND_MAX;
}

typedef struct Neuron{
        double z;
        double sum;
        double *weight;
        int num_conexoes;

}Neuron;

typedef struct layer{
    Neuron** neurons;
    int num_neuronios;
}Layer;

typedef struct neuralNetwork{
    Layer** MultiLayer;
    int num_layer;
    double output;
}neuralNetwork;


typedef struct input{
    double *input;
    int tamanho;
}inputs;

inputs* create_Input(){
    double *input={0,0,0,0};

}
Neuron* create_Neuron(int num){
    Neuron* neuron=malloc(sizeof(Neuron));
    neuron->num_conexoes=num;
    neuron->z=0;
    neuron->sum=0;
    for (int i=0;i<num;i++){
        neuron->weight[i]=rand_float();
    }
    return neuron;
}

Layer* Create_Layer(int num_neuronios){
    Layer* layer=malloc(sizeof(layer));
    layer->num_neuronios=num_neuronios;
    layer->neurons=malloc(sizeof(Neuron*)*num_neuronios);
    for(int i=0;i<num_neuronios;i++){
        layer->neurons[i]=create_Neuron(num_neuronios);
    }
    return layer;
}

neuralNetwork* create_Neural_Network(int num_layers, int num_neuronios){
        neuralNetwork* NeuralNetwork= malloc(sizeof(neuralNetwork));
        NeuralNetwork->num_layer=num_layers;
        NeuralNetwork->output=0;
        for(int i=0;i<num_layers;i++){
            NeuralNetwork->MultiLayer[i]=Create_Layer(num_neuronios);
        }
        return NeuralNetwork;
}
float sigmoidf(float sum){
    return sum;
}


void feedForward(neuralNetwork *neuralNetwork, inputs input){
    for(int i=0;i<neuralNetwork->num_layer;i++){
        if(i==0){
            for(int j=0;j<neuralNetwork->MultiLayer[0]->num_neuronios;j++){
                double sum=0;
                for(int k=0;k<input.tamanho;k++){
                    sum+=input.input[k]*neuralNetwork->MultiLayer[i]->neurons[j]->weight[k];
                }
                neuralNetwork->MultiLayer[0]->neurons[j]->sum=sum;
                neuralNetwork->MultiLayer[0]->neurons[j]->z=sigmoidf(sum); 
            }
        }
        else{
            for(int j=0;j<neuralNetwork->MultiLayer[0]->num_neuronios;j++){
                double sum=0;
                for(int k=0;k<neuralNetwork->MultiLayer[0]->num_neuronios;k++){
                    sum+=neuralNetwork->MultiLayer[i-1]->neurons[k]->z*neuralNetwork->MultiLayer[i]->neurons[j]->weight[k];
                }
                neuralNetwork->MultiLayer[i]->neurons[j]->sum=sum;
                neuralNetwork->MultiLayer[i]->neurons[j]->z=sigmoid(sum); 
            }
        }
        for(int i=0;i<neuralNetwork->MultiLayer[0]->num_neuronios;i++){
        neuralNetwork->output+=neuralNetwork->MultiLayer[neuralNetwork->num_layer-1]->neurons[i]->z;
        }
        neuralNetwork->output=sigmoidf(neuralNetwork->output);
    }

}


int main(){
    
}