#include <stdio.h>
#include <stdlib.h>
#define NENRITU_PERCENT 15.00

int main(void) {
	int price;// 支払残高
	int pay; // 設定支払額
	int paid; // 実際の支払額
	int month;// 月
	double fee = NENRITU_PERCENT*0.01 / 12.0;// 手数料率
	int tax;// 当月手数料
	int total = 0; // 合計支払額
	int taxtotal = 0; // 合計手数料

	puts("楽天カードあとからリボシミュレータ v.0.1");
	printf("商品金額を入力　　：");
	scanf("%d", &price);
	getchar();
	printf("毎月の支払額を入力：");
	scanf("%d", &pay);
	getchar();

	// printf("商品金額=%d\n支払額=%d\n", price, pay);
	printf("\n");

	for (month = 1 ; price > 0 ; month++) {
		printf("%dヵ月目\n", month);

		tax = (int)(price * fee + 0.5);

		if (pay < price) {
			paid = pay + tax;
			price -= pay;
		}else{// 支払い満了月
			paid = price + tax;
			price = 0;
		}

		total += paid;
		taxtotal += tax;

		printf("支払い額: %d円\n", paid);
		printf("残り:     %d円\n\n", price);
	}
	printf("合計の支払額: %d円\n", total);
	printf("支払う手数料: %d円\n", taxtotal);

	system("pause");

	return 0;
}