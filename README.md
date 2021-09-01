# Auto-detection reservoir models 
**Note**
This project was published in [Advances in Geo-Energy Research](https://www.yandy-ager.com/index.php/ager/article/view/252).

## Project description
CO2 injection into sub-surface oil reservoirs is a well-established technique for enhancing oil recovery. However, as CO2 is a gas and gases have low reservoir-sweep efficiency, injecting CO2 together with surfactant in the form of a foam can significantly improve its reservoir sweep efficiency. So, foam-CO2 flooding of petroleum reservoirs is a highly effective method able to enhance oil recovery from many reservoirs. Conducting laboratory experiments to assess the oil production and recovery factor performance associated with injecting foam-CO2 into specific oil reservoirs is expensive and time consuming. 
.
Simulation techniques can be a viable alternative if they can provide accurate predictions of flow rate and recovery factor from a standard set of input variables. Here, we couple a radial basis function (RBF) with evolutionary algorithms (particle swarm, imperialist competitive, genetic and teaching-learning based) to develop four hybrid-RBF prediction networks and apply them to predict efficiency of foam-CO2 flooding in oil reservoirs. A dataset with 214 published data records was compiled and used to train, optimize and test the four hybrid-RBF networks. The teaching-learning-based optimized (TLBO-RBF) model achieved the most accurate prediction performance for estimating oil flow rate (RMSE =0.0029, R2 = 0.993) oil recovery factor (RMSE =0.0872, R2 = 0.998) for the foam-CO2 injection EOR dataset. It can therefore be considered as another algorithm to estimate the performance of foam-CO2 injection in oil reservoirs efficiently while experimental data is not available.

## Dataset
You can download dataset from [Excel file](https://github.com/acse-srm3018/ReservoirClassification/blob/main/dataset.xlsx).
You can download pressure derivative dataset from [Excel file](https://github.com/acse-srm3018/ReservoirClassification/blob/main/dataset.xlsx).
The dataset includes 3250 data within 6 clases that will be used for training ANN models.


## Models Comparsion and choosing

We trained different models to compare them and find the best ones based on their performance. 

The images of performance of different models on original datasets can be find under [images](https://github.com/acse-srm3018/FoamCO2Prediction/tree/main/images) directory. Based on the comparison of the accuracy and loss of the training and validation data, the ... and ... models were idetified as the best.

## Model Properties 

The results of the grid search is given in the tables which can be found in the [supplementary files](https://github.com/acse-srm3018/FoamCO2Prediction/tree/main/supplemantaryfile) directory.
        
## Data Preprocessing

Mean and standard deviation, Max and min of training and validation set were calcualted. Then pressure data standardized and normalized using these statistical values.
            

## Installation

you can clone and open directories using

```
git clone https://github.com/acse-srm3018/FoamCO2Prediction
```

## Unit testing

To run the unit test suite
```
python tests.py
```

## Documentation

To generate the documentation (in html format)
```
python -m sphinx docs html
```

See the `docs` directory for the preliminary documentation provided that you should add to.

Also the articles published and can be found [here](https://github.com/acse-srm3018/ReservoirClassification/blob/main/document.pdf).


## Further investigation

- Increasing number of data in dataset preparing more data using simulator or real labratory data.

## References

