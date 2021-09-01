# Auto-detection reservoir models 
**Note**
This project was published in [Advances in Geo-Energy Research](https://www.yandy-ager.com/index.php/ager/article/view/252).

## Project description
Horizontal wells sense multiple points without need to drill additional vertical wells became economically viable after 1980s. Characterization of this system is required for estimation their production ability, management their behaviors, and designing enhanced recovery scenarios. Well testing signals are the most valuable source of information for characterization of hydrocarbon reservoirs having horizontal wells. Estimation of reservoir parameters as well as extent of reliability of this estimation directly depends on correct detection of reservoir interpretation model.  Indeed, it is traditional to detect reservoir model using well testing analysis prior to starting parameter estimation.
The multi-layer perceptron (MLP) neural network have widely used for pattern recognition in different scientific and engineering branches up to now. Therefore, different topologies for the MLP paradigms were examined for identifying the reservoir models from the pressure derivative curves. 2560 of pressure derivative graphs for six reservoir models are utilized for designing the most reliable MLP neural network model.


Considering some statistical and computational criteria, the multi-layer perceptron (MLP) neural network model with five hidden neurons trained with the scaled conjugate gradient are chosen as a best intelligent model for the considered task. This model provides total classification accuracy (TCA) of 98.3%, mean square errors (MSE) of 0.00725, and regression coefficient (R2) of 0.97332. Finally the developed model has been examined using real field data, noisy data and some data sets outside the range of train and test data. In all cases, the network was able to detect the correct reservoir model with the probability near to 90%.

## Data generation
The data was generated using PanSystem and then we used a QTBindCode using C to automatically generated data (pressure data). The codes can be found [here](https://github.com/acse-srm3018/ReservoirClassification/tree/main/GenerationData). 

After that we used a pressure derivative function to take derivative.


## Dataset
You can download dataset from [Excel file 1](https://github.com/acse-srm3018/ReservoirClassification/blob/main/dataset.xlsx).
and derivative dataset from [Excel file 2](https://github.com/acse-srm3018/ReservoirClassification/blob/main/dataset.xlsx).

The dataset includes 3250 data within 6 clases that will be used for training ANN models.


## Models Comparsion and choosing

We trained different models with different number of neurons in hidden layers to compare them and find the best ones based on their performance. 

        
## Data Preprocessing

Mean and standard deviation, Max and min of training and validation set were calcualted. Then pressure derivative data standardized and normalized using these statistical values.
            

## Installation

you can clone and open directories using

```
git clone https://github.com/acse-srm3018/ReservoirClassification
```

## Documentation

 The articles published and can be found [here](https://github.com/acse-srm3018/ReservoirClassification/blob/main/document.pdf).


## Further investigation

- Increasing number of data in dataset preparing more data using simulator or real labratory data.

## References

* PanSystem. 2018. Reservoir modeling software by Weatherford. https://www.weatherford.com/en/products-and-services/software/production-optimization-platform/reservoir-modeling-and-monitoring/ [accessed May 2018]
