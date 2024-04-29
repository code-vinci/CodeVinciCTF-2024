#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNAUTHORIZED 1 

typedef struct {
	char nome[32];
	char password[32];
	int level;
	int money;
} account;

void banner() {
	printf("Bank Manager - Beta 1.0\n");
	printf("-----------------------\n");
}

void buffering() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

int main() {
	buffering(); 

	int scelta;
	char buff_nome[32];
	char buff_password[32];
	int found = 0;
	FILE *f = fopen("accounts.txt", "ra");

	account acc = {
		.nome = {},
		.password = {},
		.level = UNAUTHORIZED,
		.money = 100,
	};

	do {
		system("clear");
		banner();
		printf("[1] - Registrati\n");
		printf("[2] - Login\n");
		printf("[3] - Exit\n");
		printf("Benvenuto, cosa vuoi fare?");
		scanf("%d", &scelta);
	} while (scelta < 1 || scelta > 3);

	switch (scelta) {
		case 1:
			acc.level = UNAUTHORIZED;

			printf("Inserisci il tuo username: ");
			scanf("%32s", acc.nome);
			printf("Inserisci la tua password: ");
			scanf("%32s", acc.password);
			fprintf(f, "%s-%s-%d\n", acc.nome, acc.password, acc.level);
			printf("Benvenuto/a %s!\n", acc.nome);
			break;
		case 2:
			printf("Inserisci il tuo username: ");
			scanf("%s", buff_nome);
			printf("Inserisci la tua password: ");
			scanf("%s", buff_password);

			rewind(f);
			while (fscanf(f, "%[^-]-%[^-]-%d-%d\n", acc.nome, acc.password, &acc.level, &acc.money) != EOF) {
				if (strcmp(acc.nome, buff_nome) == 0 && strcmp(acc.password, buff_password) == 0) {
					found = 1;
					break;
				}
			}

			if (found) {
				printf("Bentornato/a %s!\n", acc.nome);
			} else {
				printf("Credenziali errate, stai cercando di rubare un account? >:(\n");
				exit(0);
			}
			break;
		case 3:
			printf("\nArrivederci!");
			exit(0);
	}

	scelta = 99;
	do {
		printf("Il tuo saldo e' di %d\n", acc.money);

		if (acc.level != UNAUTHORIZED)
			printf("[0] - Show flag\n");

		printf("[1] - Preleva soldi.\n");
		printf("[2] - Dona dei soldi.\n");
		printf("[3] - Exit.\n");
		printf("Cosa vuoi fare? ");
		scanf("%d", &scelta);
	} while (scelta < 0 || scelta > 3);

	int moneybuff = 0;

	switch (scelta) {
		case 0:
			if (acc.level != UNAUTHORIZED)
				puts(getenv("FLAG"));
			else
				printf("\nNon hai abbastanza permessi.");
			break;
		case 1:
			printf("Quanti soldi vuoi prelevare? ");
			scanf("%d", &moneybuff);
			if (moneybuff <= acc.money && moneybuff > 0) {
				printf("Hai prelevato %d euro.", moneybuff);
				acc.money -= moneybuff;
			} else {
				printf("Non hai abbastanza soldi.");
			}
			break;
		case 2:
			printf("Quanti soldi vuoi donare? ");
			scanf("%d", &moneybuff);
			if (moneybuff <= acc.money && moneybuff > 0) {
				printf("Hai donato %d euro.", moneybuff);
				acc.money -= moneybuff;
			} else {
				printf("Non hai abbastanza soldi.\n");
			}
			break;
		case 3:
			printf("Arrivederci.\n");
			exit(0);
			break;
	}

	fclose(f);
	return 0;
}
