#include < stdio.h >
int Admatrix[25][25], marked_cities[10], limit, dist = 0;

int demo_algo(int c) {
    int count, nearest_city = 999;
    int minimum = 999, temp;
    for (count = 0; count < limit; count++) {
        if ((Admatrix[c][count] != 0) && (marked_cities[count] == 0)) {
            if (Admatrix[c][count] < minimum) {
                minimum = Admatrix[count][0] + Admatrix[c][count];
            }
            temp = Admatrix[c][count];
            nearest_city = count;
        }
    }
    if (minimum != 999) {
        dist = dist + temp;
    }
    return nearest_city;
}

void minimum_dist(int city) {
    int nearest_city;
    marked_cities[city] = 1;
    printf("%d ", city + 1);
    nearest_city = demo_algo(city);
    if (nearest_city == 999) {
        nearest_city = 0;
        printf("%d", nearest_city + 1);
        dist = dist + Admatrix[city][nearest_city];
        return;
    }
    minimum_dist(nearest_city);
}

int main() {
    int i, j;
    printf("Enter Total Number of Cities:\t");
    scanf("%d", & limit);
    printf("\nEnter Cost Matrix\n");
    for (i = 0; i < limit; i++) {
        printf("\n Enter %d Elements in %d Row \n", limit, i + 1);
        for (j = 0; j < limit; j++) {
            scanf("%d", & Admatrix[i][j]);
        }
        marked_cities[i] = 0;
    }
    printf("\n Entered Matrix is \n");
    for (i = 0; i < limit; i++) {
        printf("\n");
        for (j = 0; j < limit; j++) {
            printf("%d ", Admatrix[i][j]);
        }
    }
    printf("\n\nPath:\t");
    minimum_dist(0);
    return 0;
}