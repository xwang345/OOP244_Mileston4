#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

#include "Product.h"

using namespace std;

namespace sict{
    Product::Product() {
        sku_[0] = '\0';
        name_ = NULL;
        price_ = 0;
        taxed_ = 0;
        quantity_ = 0;
        qtyNeeded_ = 0;
    }

    Product::Product (const char* sku, const char* name, bool taxed, double price, int quantity) {
        if(sku_[0] != '\0' && name_!= nullptr) {
            strcpy(sku_,sku);
            name_ = nullptr;
            name_ = new char[strlen(name) +1];
            strcpy(name_, name);
            quantity_ = quantity;
            price_ = price;
            taxed_ = taxed;
        } else {
            sku_[0] = '\0';
            name_ = nullptr;
            price_ = 0;
            taxed_ = 0;
            quantity_ = 0;
        }
    }

    Product::Product(const char *sku, const char *name){
        strcpy(sku_, sku);
        strcpy(name_, name);
    }


    Product& Product::operator=(const Product &other) {
        if(!Product::isEmpty()) {
            Product::name(other.name_);
            quantity_ = other.quantity_;
        }
        return *this;
    }

    Product::~Product() {
        delete[] name_;
        name_ = nullptr;
    }

    void Product::sku(const char *sku) {
        strncpy(sku_, sku, MAX_SKU_LEN + 1);
    }

    void Product::name(const char *name) {
        delete[] name_;
        name_ = new char[strlen(name) + 1];
        strcpy(name_, name);
    }

    void Product::price(double price) {
        price_ = price;
    }

    void Product::taxed(bool taxed) {
        taxed_ = taxed;
    }

    void Product::quantity(int quantity) {
        quantity_ = quantity;
    }

    void Product::qtyNeeded(int qtyNeeded) {
        qtyNeeded_ = qtyNeeded;
    }

    //TODO Getter
    const char* Product::sku() const {
        return sku_;
    }

    char* Product::name() const {
        return name_;
    }

    double Product::price() const {
        return price_;
    }

    bool Product::taxed() const {
        return taxed_;
    }

    int Product::quantity() const {
        return quantity_;
    }

    int Product::qtyNeeded() const {
        return qtyNeeded_;
    }

    double Product::cost() const {
        if(Product::taxed()){
            return price_*(1+TAX);
        } else {
            return price_;
        }
    }

    const bool Product::isEmpty() const {
        if(sku_[0] == '\0' && name_ == nullptr && price_ == 0 && qtyNeeded_ == 0 && taxed_ == false) {
            return false;
        }
        return true;
    }

    bool Product::operator==(const char *temp) {
        return (sku_ == temp);
    }

    int Product::operator+=(const int add) {
        int temp;
        temp = add + quantity_;
        quantity_ = temp;
        return quantity_;
    }

    int Product::operator-=(const int min) {
        return quantity_ - min;
    }

    double operator+=(double& left, const Product& item) {
        return left + (item.price()*item.quantity());
    }

    std::istream& operator >> (std::istream& is, Product& I) {
        I.read(is);
        //I.read(is);
        return is;
    }
    std::ostream& operator<<(std::ostream&os, const Product& I)
    {

        I.write(os, true);
        return os;
    }

}