#include <iostream>
#include <cstdlib>
class Dataset {
private:
    double* vardnty;
    double* varintx;
public:
    // Constructor
    Dataset(double* datos1, double* datos2) : vardnty(datos1), varintx(datos2) {
    }
    ~Dataset() {
        delete[] vardnty;
        delete[] varintx;
    }
    double* getVardnty() const {
        return vardnty;
    }
    double* getvarintx() const {
        return varintx;
    }
};
int main() {
    int tamdata = 9;
    double* varsy = new double[tamdata] {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};
    double* varsx = new double[tamdata] {23, 26, 30, 34, 43, 48, 52, 57, 58};
    Dataset datasetvals(varsy, varsx);
    double varxpredict, varypredict, beta1, beta0, sumxy, sumxsqr, sumx, sumy, rsquared, ssr, sst,yhat;
    std::cout << "Introduzca X para predecir Y: ";
    std::cin >> varxpredict;
    sumxy = 0;
    sumxsqr = 0;
    sumx = 0;
    sumy = 0;
    ssr = 0;
    sst = 0;
    for (int i = 0; i < tamdata; i++) {
        sumx += datasetvals.getvarintx()[i];
        sumy += datasetvals.getVardnty()[i];
        sumxy += (datasetvals.getvarintx()[i] * datasetvals.getVardnty()[i]);
        sumxsqr += (datasetvals.getvarintx()[i] * datasetvals.getvarintx()[i]);
    }
    beta1 = ((tamdata * sumxy) - (sumx * sumy)) / ((tamdata * sumxsqr) - (sumx * sumx));
    beta0 = (sumy - (beta1 * sumx)) / tamdata;
    varypredict = beta0 + (beta1 * varxpredict);
    for (int i = 0; i < tamdata; i++) {
        yhat = beta0 + beta1 * datasetvals.getvarintx()[i];
        ssr = ssr+((yhat - (sumy / tamdata)) * (yhat - (sumy / tamdata)));
        sst = sst+((datasetvals.getVardnty()[i] - (sumy / tamdata)) * (datasetvals.getVardnty()[i] - (sumy / tamdata)));
    }
    rsquared = ssr / sst;
    std::cout << "Y = B0 + B1*X1" << std::endl;
    std::cout << "Y = (" << beta0 << ") + (" << beta1 << ")*X1" << std::endl;
    std::cout << "Y = " << varypredict << std::endl;
    std::cout << "R-squared = " << rsquared << std::endl;
    delete[] varsy;
    delete[] varsx;
    return 0;
}
