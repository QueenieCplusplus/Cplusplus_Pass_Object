// 2019, 11/25, 11:30, by Queenie
// 藉由參照傳遞物件

#include <stdio.h>
#include<stdlib.h>

// return 是 & 參照（記憶體位址）
int& INT::operator+= int(const int& i)
{
    int* j = elem;
    int* k = i.elem;
    *j++ += *k++;
    return *this;
}

int main() {
    return 0;
}
