#define _CRT_SECURE_NO_WARNINGS
// main.c
#include <stdio.h>
#include "product.h"
#include "cart.h"

int main() {
    Product products[MAX_PRODUCTS];
    CartItem cart[MAX_PRODUCTS];
    int product_count = 0;
    int cart_count = 0;
    int choice;

    while (1) {
        printf("\nE-commerce Backend\n");
        printf("1. Add Product\n");
        printf("2. List Products\n");
        printf("3. Add to Cart\n");
        printf("4. View Cart\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        // Clear the input buffer
        while (getchar() != '\n');

        switch (choice) {
        case 1:
            add_product(products, &product_count);
            break;
        case 2:
            list_products(products, product_count);
            break;
        case 3:
        {
            int product_index, quantity;
            printf("Enter product index: ");
            scanf("%d", &product_index);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            // Clear the input buffer
            while (getchar() != '\n');
            add_to_cart(cart, &cart_count, products, product_index - 1, quantity);
        }
        break;
        case 4:
            view_cart(cart, cart_count, products);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
