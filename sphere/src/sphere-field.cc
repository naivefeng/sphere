/*
 * sphere-field.cc
 *
 * The implementations for fields
 *
 * Wahlque Sphere Project
 *
 * MIT License
 *
 */

#include "sphere-field.h"
#include "sphere-index.h"
#include "sphere-geoind.h"

namespace sphere {

    ScalarField::ScalarField(int level, double cnst) {
        this->level = level;
        this->size = all(level);
        this->data = new double[size];

        for (int i = 0; i < size; i++) {
            this->data[i] = cnst;
        }
    }

    ScalarField::~ScalarField() {
        delete [] this->data;
        this->data = NULL;
    }

    ScalarField & ScalarField::operator=(const ScalarField &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->size = rhs.size;
        this->data = new double[this->size];
        for (int i = 0; i < size; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    }

    const ScalarField::proxy ScalarField::operator[](int index) const {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    ScalarField::proxy ScalarField::operator[](int index) {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    /*
    double ScalarField::operator()(double lng, double lat) {
    }
    */

    ScalarField& ScalarField::operator+=(const ScalarField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] + rhs[i];
        }

        return (*this);
    }

    ScalarField& ScalarField::operator-=(const ScalarField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] - rhs[i];
        }

        return (*this);
    }

    ScalarField& ScalarField::operator*=(const double &cnst) {
        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] * cnst;
        }

        return (*this);
    }

    ScalarField& ScalarField::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            (*this)[i] = (*this)[i] / cnst;
        }

        return (*this);
    }

    VectorField::VectorField(int level, Vector* cnst) {
        this->level = level;
        this->size = all(level);
        this->data = new Vector[size];

        for (int i = 0; i < size; i++) {
            this->data[i] = *cnst;
        }
    }

    VectorField::~VectorField() {
        delete [] this->data;
        this->data = NULL;
    }

    VectorField & VectorField::operator=(const VectorField &rhs) {
        if (this == &rhs)
            return *this;

        if (this->data != NULL)
            delete [] this->data;

        this->level = rhs.level;
        this->size = rhs.size;
        this->data = new Vector[this->size];
        for (int i = 0; i < size; i++) {
            this->data[i] = rhs.data[i];
        }

        return *this;
    }

    const VectorField::proxy VectorField::operator[](int index) const {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    VectorField::proxy VectorField::operator[](int index) {
        int size = this->size;
        index = index % size;
        if (index < 0) index = index + size;
        return proxy(this->data[index]);
    }

    /*
    double VectorField::operator()(double lng, double lat) {
    }
    */

    VectorField& VectorField::operator+=(const VectorField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] += rhs.data[i];
        }

        return (*this);
    }

    VectorField& VectorField::operator-=(const VectorField &rhs) {
        if(this->level != rhs.level)
            throw "granularity of the two fields is mismatched!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] -= rhs.data[i];
        }

        return (*this);
    }

    VectorField& VectorField::operator*=(const double &cnst) {
        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] *= cnst;
        }

        return (*this);
    }

    VectorField& VectorField::operator/=(const double &cnst) {
        if(cnst == 0)
            throw "divided by zero!";

        for(int i = 0, len = all(this->level); i < len; i++) {
            this->data[i] /= cnst;
        }

        return (*this);
    }

}

