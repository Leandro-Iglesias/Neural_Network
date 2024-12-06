#include<stdio.h>
#include<stdlib.h>

typedef struct Neuron{
        double z;
        double sum;
        double *weight;
}Neuron;

typedef struct layer{
    Neuron *neurons;
    int num_neuronios;
}Layer;

typedef struct neuralNetwork{
    Layer *MultiLayer;
    int num_multilayer;
    double output;
}neuralNetwork;


typedef struct input{
    double *input;
    int tamanho;
}inputs;


void feedForward(neuralNetwork *neuralNetwork, inputs input){
    for(int i=0;i<neuralNetwork->num_multilayer;i++){
        if(i==0){
            for(int j=0;j<neuralNetwork->MultiLayer->num_neuronios;j++){
                double sum=0;
                for(int k=0;k<input.tamanho;k++){
                    sum+=input.input[k]*neuralNetwork->MultiLayer[i].neurons[j].weight[k];
                }
                neuralNetwork->MultiLayer->neurons[j].sum=sum;
                neuralNetwork->MultiLayer->neurons[j].z=sigmoidf(sum); 
            }
        }
        else{
            for(int j=0;j<neuralNetwork->MultiLayer->num_neuronios;j++){
                double sum=0;
                for(int k=0;k<neuralNetwork->MultiLayer->num_neuronios;k++){
                    sum+=neuralNetwork->MultiLayer[i-1].neurons[k].z*neuralNetwork->MultiLayer[i].neurons[j].weight[k];
                }
                neuralNetwork->MultiLayer[i].neurons[j].sum=sum;
                neuralNetwork->MultiLayer[i].neurons[j].z=sigmoid(sum); 
            }
        }
        for(int i=0;i<neuralNetwork->MultiLayer->num_neuronios;i++){
        neuralNetwork->output+=neuralNetwork->MultiLayer[neuralNetwork->num_multilayer-1].neurons[i].z;
        }
        neuralNetwork->output=sigmoidf(neuralNetwork->output);
    }

float sigmoidf(float sum){
    return sum;
}




    
}


int main(){
    
}