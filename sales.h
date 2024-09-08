#ifndef SALES_H
#define SALES_H
#define MAX_SALES 500

typedef struct {
    char phoneModel[100];
    int quantity;
    float unitPrice;
    float totalPrice;
} SaleRecord;

extern SaleRecord sales[MAX_SALES];
extern int sale_count;
extern float total_revenue;

float calculateSales();
void recordSale(char* phoneModel, int quantity, float unitPrice);
void viewSalesHistory();

#endif