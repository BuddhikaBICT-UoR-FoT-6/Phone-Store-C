#include "utils.h"
#include <ctype.h>
#include <string.h>
#include <stdio.h>

// Validate if input is a positive integer
int validate(int x) {
    return x > 0 ? 1 : 0;
}

// Validate price format (should be positive and not exceed reasonable limit)
int validatePrice(float price) {
    return (price > 0.0f && price < 1000000.0f) ? 1 : 0;
}

// Validate stock quantity (positive integer)
int validateStock(int stock) {
    return (stock >= 0 && stock <= 999999) ? 1 : 0;
}

// Calculate discount based on quantity purchased
float calculateDiscount(float price, float discountPercent) {
    if (discountPercent < 0.0f || discountPercent > 100.0f) {
        return price;
    }
    return price * (1.0f - discountPercent / 100.0f);
}

// Calculate tiered discount by quantity
float calculateQuantityDiscount(int quantity, float price) {
    float discountRate = 0.0f;
    
    // Tiered discount system
    if (quantity >= 50) {
        discountRate = 0.20f;  // 20% discount for 50+ units
    } else if (quantity >= 25) {
        discountRate = 0.15f;  // 15% discount for 25-49 units
    } else if (quantity >= 10) {
        discountRate = 0.10f;  // 10% discount for 10-24 units
    } else if (quantity >= 5) {
        discountRate = 0.05f;  // 5% discount for 5-9 units
    }
    
    return price * discountRate;
}

// Format currency with proper precision
char* formatCurrency(float amount) {
    static char buffer[50];
    if (amount < 0) {
        sprintf(buffer, "Rs. -%.2f", -amount);
    } else {
        sprintf(buffer, "Rs. %.2f", amount);
    }
    return buffer;
}

// Validate phone name input
int validatePhoneName(const char* name) {
    if (name == NULL || strlen(name) == 0) {
        return 0;  // Empty name is invalid
    }
    if (strlen(name) > 50) {
        return 0;  // Name too long
    }
    return 1;  // Valid name
}

// Validate phone model input
int validatePhoneModel(const char* model) {
    if (model == NULL || strlen(model) == 0) {
        return 0;
    }
    if (strlen(model) > 30) {
        return 0;
    }
    return 1;
}

// Format large numbers with thousands separator
char* formatNumber(int number, char* buffer) {
    if (buffer == NULL) {
        return NULL;
    }
    
    if (number < 1000) {
        sprintf(buffer, "%d", number);
    } else if (number < 1000000) {
        sprintf(buffer, "%d,%03d", number / 1000, number % 1000);
    } else {
        sprintf(buffer, "%d,%03d,%03d", number / 1000000, (number / 1000) % 1000, number % 1000);
    }
    
    return buffer;
}

// Calculate total revenue
float calculateTotal(int quantity, float unitPrice) {
    if (!validateStock(quantity) || !validatePrice(unitPrice)) {
        return 0.0f;
    }
    return (float)quantity * unitPrice;
}
