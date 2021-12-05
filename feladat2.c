/***********************************************************************
* A PROGRAMBAN NEM SZEREPELHETNEK AZ ALÁBBI SOROK:
* #include <string.h>
* #include <math.h>
***********************************************************************/
#include <stdio.h>
#include <stdlib.h>

/***********************************************************************
************************************************************************
**		ETTŐL A PONTTÓL DOLGOZHATSZ A FELADATOKON
************************************************************************
***********************************************************************/

/*
1. feladat (4 pont)

Az alabbi fuggveny elso parametere egy egeszek sorozatat tarolo tomb,
amiben a sorozat veget a -1 ertek jelzi. 

A feladat a fuznivalo nevu
hasonlo tomb elemeinek hozzafuzese az elso parameterhez.

 A feladat
megoldhato ket ciklus segitsegevel. 
Az elso egyszeruen atmasolja az
elso parameterben kapott tomb elemeit az eredmeny-tombbe.
 A masodik
ciklus ket szamlaloja kozul az elso az eredmeny-tomb vegenel indul, a
masodik a hozzafuzendo tomb elejerol. 

Minden lepesben a masodik szamlalo
altal mutatott elemet kell atirni az eredmeny-tomb elso szamlalo altal
mutatott helyere. Figyelj arra, hogy az eredmeny-tomb veget lezard a
-1 ertekkel!
Az eredmenyt a masodik parameterben kapott eredmeny nevu tombben kell
elkesziteni.
Kodold le a fuggvenyt C nyelven. A fuggveny fejlecen ne valtoztass!
*/
void tombosszefuzes(int tomb[], int eredmeny[], int fuznivalo[]) {
		int i;
		for ( i= 0; tomb[i] != -1; ++i){
			eredmeny[i] = tomb[i];
		}

		for (int k = 0; fuznivalo[k] !=-1; ++k){
			
					eredmeny[i]=fuznivalo[k];
					++i;
				
		}
		eredmeny[i]= -1;

}

/*
2. feladat (4 pont)

Irj egy haromszog nevu strukturat, ami az
a es m nevu float tipusu mezoiben
egy haromszog alapjat illetve a hozza tartozo magassagot tarolja.
Irj egy compare nevu fuggvenyt, ami ket ilyen
haromszoget kap parameterul, es a nagyobb teruletuvel ter vissza.
Amennyiben a ket haromszog terulete egyforma, akkor a fuggveny
az elso parameterben kapott haromszoget adja vissza.
A haromszog terulete: (a*m)/2.
*/
/****************************************************
 * A kovetkezo sor programba illesztese eseten      *
 * (// torlese a #define elol) a feladat nem okoz   *
 * forditasi hibat, de pontot sem fog erni.         *
 ****************************************************/
//#define KIHAGY_2
typedef struct {
    float a, m; //alap a, magassag m
} haromszog;



#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))

haromszog compare(haromszog h1, haromszog h2) {

	int terulet_h1=0;
	int terulet_h2=0;
	terulet_h1=(h1.a*h1.m)/2;
	terulet_h2=(h2.a*h2.m)/2;


	if(terulet_h1 >= terulet_h2){
		return h1;
	}else{
		return h2;
	}
}

#endif

/*
3. feladat (6 pont)

Az alabbi fuggveny feladata helyet foglalni egy ketdimenzios char tombnek.
A tomb sor- es oszlopszama megegyezik.
A tomb N meretet a fuggveny parameterkent kapja.
A helyfoglalas ugy tortenjen, hogy eloszor helyet foglalunk az N sor
pointereinek, majd megfelelo modon minden sor N-N darab elemenek is.
A helyfoglalas utan toltsuk fel a tomb elemeit ertekekkel a kovetkezo modon:
A tomb ,,atloi'' --- azaz azon elemek, melyek sor- es oszlopindexe megegyezik, vagy
ezek osszege N-1 --- legyenek 'x', belso elemei pedig 'e' ertekuek.
A fuggveny terjen vissza a tombre mutato pointerrel. A memoria felszabaditasaval
nem kell foglalkoznod.
*/


char **foglal(int n) {
	char **str;

  str = (char**)malloc(n*sizeof(char*));
	for (int i = 0; i < n; ++i)
	{
		str[i] = (char*)malloc(n*sizeof(char));
		for (int j = 0; j < n; ++j)
		{
			if(i==j || i+j == n-1){
				str[i][j]='x';
			}else{
				str[i][j]='e';
			}
		}
		
	}
 
  return str;

}
/***********************************************************************
************************************************************************
**
**	EZEN A PONTON TÚL NE VÁLTOZTASS SEMMIT SEM A FÁJLON!
**
************************************************************************
***********************************************************************/

void call_1()
{
	char x=0;
	int i, n=0, m=0, a[32]={-2}, c[32]={-2}, r[32];
	for(i=0;i<32;++i) r[i]=-2;
	if(fscanf(stdin, "%c", &x)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	if(fscanf(stdin, "%d", &n)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	for(i=0; i<n; i++) {
		if(fscanf(stdin, "%d", a+i)!=1) {
			fprintf(stderr, "HIBA: Nem olvasható adat!\n");
			return;
		}
	}
	a[n]=-1;
	if(fscanf(stdin, "%d", &m)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	for(i=0; i<m; i++) {
		if(fscanf(stdin, "%d", c+i)!=1) {
			fprintf(stderr, "HIBA: Nem olvasható adat!\n");
			return;
		}
	}
	c[m]=-1;
	tombosszefuzes(a, r, c);
	if(x=='R') {
		fprintf(stdout, "%d\n", r[n+m]);
	} else if(x=='E') {
		for(i=0; i<n+m; i++) {
			fprintf(stdout, "%d\n", r[i]);
		}
	} else {
		for(i=0; r[i]!=-1; i++) {
			fprintf(stdout, "%d\n", r[i]);
		}
	}
}
void test_1()
{
    int i, j, tomb[20] = {0}, eredmeny[20] = {0};
    struct {int tomb[20]; int fuznivalo[20]; int eredmeny[20];} testlist[2] = {
        {{1,2,3,-1}, {4,5,6,-1},   {1,2,3,4,5,6,-1}},
        {{-1},       {5,4,5,4,-1}, {5,4,5,4,-1}    },
    };
    for (i = 0; i < 2; ++i) {
        for(j = 0; testlist[i].tomb[j] != -1; tomb[j] = testlist[i].tomb[j], ++j);
        tomb[j] = -1;
        tombosszefuzes(tomb, eredmeny, testlist[i].fuznivalo);
        for(j = 0; eredmeny[j] != -1 && testlist[i].eredmeny[j] != -1 && eredmeny[j] == testlist[i].eredmeny[j]; ++j);
        if (eredmeny[j] != testlist[i].eredmeny[j]) {
            fprintf(stderr, "HIBA: tombosszefuzes({");
            for(j = 0; testlist[i].tomb[j] != -1; fprintf(stderr, "%d,", testlist[i].tomb[j++]));
            fprintf(stderr, "-1}, {...}, {");
            for(j = 0; testlist[i].fuznivalo[j] != -1; fprintf(stderr, "%d,", testlist[i].fuznivalo[j++]));
            fprintf(stderr, "-1})\n");
            fprintf(stderr, "\telvárt eredmény: {");
            for(j = 0; testlist[i].eredmeny[j] != -1; fprintf(stderr, "%d,", testlist[i].eredmeny[j++]));
            fprintf(stderr, "-1}\n");
            fprintf(stderr, "\tkapott eredmény: {");
            for(j = 0; eredmeny[j] != -1 && j < 10; fprintf(stderr, "%d,", eredmeny[j++]));
            fprintf(stderr, "%s}\n", (j < 10) ? "-1" : "...");
        }
    }
}

void call_2(){
#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))
  int v;
  haromszog a, b, x;
  if(fscanf(stdin, "%d", &v)!=1) {
    fprintf(stderr, "HIBA: Nem olvasható adat!\n");
    return;
  }
  switch(v) {
  case 1:
    if(fscanf(stdin, "%d", &v)!=1) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    fprintf(stdout, "fordul%d\n", v);
    break;
  default:
    if(fscanf(stdin, "%f %f", &a.a, &a.m)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    if(fscanf(stdin, "%f %f", &b.a, &b.m)!=2) {
      fprintf(stderr, "HIBA: Nem olvasható adat!\n");
      return;
    }
    x = compare(a, b);
    fprintf(stdout, "[%f,%f]\n", x.a, x.m);
    break;
  }
#endif
}
void test_2(){
#if ! (defined(KIHAGY_2) || defined(KIHAGY_MIND))
  int i;
  haromszog eredmeny;
  struct {haromszog a, b, eredmeny;} testlist[2] = {
    {{.a=3, .m=10}, {.a=6, .m=5 }, {.a=3, .m=10}},
    {{.a=2, .m=5 }, {.a=3, .m=14}, {.a=3, .m=14}}
  };
  for (i = 0; i < 2; ++i) {
    eredmeny = compare(testlist[i].a, testlist[i].b);
    if (eredmeny.a != testlist[i].eredmeny.a || eredmeny.m != testlist[i].eredmeny.m) {
      fprintf(stderr, "HIBA: compare([%f,%f], [%f,%f])\n"
		      "\telvárt eredmény: [%f,%f]\n"
		      "\tkapott eredmény: [%f,%f]\n",
		      testlist[i].a.a, testlist[i].a.m, testlist[i].b.a, testlist[i].b.m,
		      testlist[i].eredmeny.a, testlist[i].eredmeny.m,
		      eredmeny.a, eredmeny.m
      );
    }
  }
#endif
}

void call_3()
{
	int chck;
	int n, i, j;
	char **ptr = NULL;
	if(fscanf(stdin, "%d %d", &chck, &n)!=2) {
		fprintf(stderr, "HIBA: Nem olvasható adat!\n");
		return;
	}
	ptr = foglal(n);
	switch (chck) {
		case 1:
			if (ptr != NULL) {
				free(ptr);
				fprintf(stdout,"%d\n", n);
			} else {
				fprintf(stdout,"NULL\n");
			}
			break;
		case 2:
			for(i=0; i<n; i++) {
				free(ptr[i]);
				fprintf(stdout,"%d", n);
			}
			fputc('\n', stdout);
			free(ptr);
			break;
		case 3:
			for(i=0; i<n; i++) {
				for(j=0; j<n; j++) {
					fputc(ptr[i][j], stdout);
				}
				fputc('\n', stdout);
			}
			break;
		default:
			if(fscanf(stdin, "%d %d", &i, &j)!=2) {
				fprintf(stderr, "HIBA: Nem olvasható adat!\n");
				return;
			}
			fprintf(stdout,"%c\n", ptr[i][j]);
			break;
	}
}
void test_3()
{
	const int n = 3;
	int i, j, k;
  char **ptr = NULL;
  struct {char ptr[3][3];} testlist[1] = {
  	{
  		{
  			{"xex"},
  			{"exe"},
  			{"xex"}
  		}
  	}
  };
  for (i = 0; i < 1; ++i) {
    ptr = foglal(n);
    if (ptr == NULL) {
    	fprintf(stderr, "HIBA: NULL pointer\n");
    	return;
    } else {
    	for (j = 0; j < n; ++j) {
    		if (ptr[j] == NULL) {
		    	fprintf(stderr, "HIBA: NULL pointer\n");
		    	return;
    		} else {
	    		for (k = 0; k < n; ++k) {
	    			if (ptr[j][k] != testlist[i].ptr[j][k]) {
	    				fprintf(stderr, "HIBA a(z) (%d,%d) pozíción\n"
	    					              "\telvárt eredmény: %c\n"
	    					              "\tkapott eredmény: %c\n",
	    					              j, k, testlist[i].ptr[j][k], ptr[j][k]);
	    				return;
	    			}
	    		}
	    	}
    	}
    }
    for (j = 0; j < n; free(ptr[j++]));
    free(ptr);
  }
}

typedef void (*call_function)();

call_function call_table[] = {
	call_1,
	call_2,
	call_3,
	NULL
};


call_function test_table[] = {
	test_1,
	test_2,
	test_3,
	NULL
};

static int __arg_check_helper(const char * exp, const char * arg) {
	while (*exp && *arg && *exp == *arg) {
		++exp;
		++arg;
	}
	return *exp == *arg;
}

int main(int argc, char *argv[])
{
	int feladat, calltabsize;
	if ((argc > 1) && !(__arg_check_helper("-t", argv[1]) && __arg_check_helper("--test", argv[1]))) {
		if (argc > 2) {
			feladat = atoi(argv[2]);
			for (calltabsize=0; test_table[calltabsize]; calltabsize++);
			if (feladat <= 0 || calltabsize < feladat) {
				fprintf(stderr, "HIBA: rossz feladat sorszám: %d!\n", feladat);
				return 1;
			}
			(*test_table[feladat-1])();
		} else {
			for (feladat=0; test_table[feladat]; ++feladat) {
				(*test_table[feladat])();
			}
		}
		return 0;
	}
	if (!freopen("be.txt", "r", stdin)) {
		fprintf(stderr, "HIBA: Hiányzik a `be.txt'!\n");
		return 1;
	}
	if (!freopen("ki.txt", "w", stdout)) {
		fprintf(stderr, "HIBA: A `ki.txt' nem írható!\n");
		return 1;
	}
	for (calltabsize=0; call_table[calltabsize]; calltabsize++);
	if (fscanf(stdin, "%d%*[^\n]", &feladat)!=1) {
		fprintf(stderr, "HIBA: Nem olvasható a feladat sorszám!\n");
		return 1;
	}
	fgetc(stdin);
	if (0<feladat && feladat<=calltabsize) {
		(*call_table[feladat-1])();
	} else {
		fprintf(stderr, "HIBA: Rossz feladat sorszám: %d!\n", feladat);
		return 1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
