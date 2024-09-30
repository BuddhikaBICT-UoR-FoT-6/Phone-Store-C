#ifndef UTILS_H
#define UTILS_H

int validate(int x);
int validatePrice(float price);
int validateStock(int stock);
float calculateDiscount(float price, float discountPercent);
char* formatCurrency(float amount);

#endif