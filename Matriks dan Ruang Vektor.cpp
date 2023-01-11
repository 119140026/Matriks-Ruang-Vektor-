#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include<iomanip>
#include <cstdlib>
#define M 10
using namespace std;

//cramer
void input(int array[][3], int array1[][1]);
int determinan(int array[][3]);
int hitung(int array[][3], int a, int b, int c);
int salin(int array[][3], int array1[][1], int a);
void eksekusi_salin(int array[][3], int array1[][3]);

//rumus invers
void cetak_matriks(float a[][M], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int operasi(float a[][M], int n)
{
    int i, j, k = 0, c, flag = 0, m = 0;
    float pro = 0;

    for (i = 0; i < n; i++)
    {
        if (a[i][i] == 0)
        {
            c = 1;
            while ((i + c) < n && a[i + c][i] == 0)
                c++;
            if ((i + c) == n)
            {
                flag = 1;
                break;
            }
            for (j = i, k = 0; k <= n; k++)
                swap(a[j][k], a[j+c][k]);
        }
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                float pro = a[j][i] / a[i][i];

                for (k = 0; k <= n; k++)
                {
                    a[j][k] = a[j][k] - (a[i][k]) * pro;
                }
            }
        }
    }
    return flag;
}

void cetak_hasil(float a[][M], int n, int flag)
{
    cout << "hasilnya adalah : ";

    if (flag == 2)
    {
      cout << "banyak solusi" << endl;
    }
    else if (flag == 3)
    {
        cout << "tidak ada solusi" << endl;
    }

    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << a[i][n] / a[i][i] << " ";
        }

    }
}

int cek(float a[][M], int n, int flag)
{
    int i, j;
    float hasil;

    flag = 3;

    for (i = 0; i < n; i++)
    {
        hasil = 0;
        for (j = 0; j < n; j++)
        {
            hasil = hasil + a[i][j];
        }
        if (hasil == a[i][j])
        {
            flag = 2;
        }

    }
    return flag;
}

//rumus determinan
int determinan( int matriks[10][10], int n) {
   int det = 0;
   int submatriks[10][10];
   if (n == 2)
   {
       return ((matriks[0][0] * matriks[1][1]) - (matriks[1][0] * matriks[0][1]));
   }
   else
   {
      for (int x = 0; x < n; x++)
      {
          int subi = 0;

          for (int i = 1; i < n; i++)
          {
                int subj = 0;

            for (int j = 0; j < n; j++)
            {
               if (j == x)
               {
                   continue;
               }

               submatriks[subi][subj] = matriks[i][j];
               subj++;
            }
            subi++;
          }
          det = det + (pow(-1, x) * matriks[0][x] * determinan( submatriks, n - 1 ));
      }
   }
   return det;
}

int main ()
{
	int pilih,pilih2;

	cout<<">>TUGAS BESAR MATRIKS DAN RUANG VEKTOR"<<endl;

	cout<<"Nama Anggota : "<<endl;
	cout<<"1. Muhammad Asyroful Nur Maulana Yusuf (119140026) "<<endl;
	cout<<"2. Muhammad A.M Hikar Syahrial (119140031)"<<endl;
	cout<<"3. Makruf Alkarhi (119140075)"<<endl<<endl;

    //menu
	menu :
	cout<<"Menu: "<<endl;
	cout<<"1. Sistem Persamaan Linier"<<endl;
	cout<<"2. Determinan"<<endl;
	cout<<"3. Matriks Balikan"<<endl;
	cout<<"4. Keluar"<<endl;
	cout<<"Pilih? ";cin>>pilih;

	if (pilih==1){
		cout<<"Menu: "<<endl;
		cout<<"1. Metode Eliminasi Gauss"<<endl;
		cout<<"2. Metode Elimminasi Gauss-Jordan"<<endl;
		cout<<"3. Metode Matriks Balikan (Invers)"<<endl;
		cout<<"4. Kaidah Cramer"<<endl;
		cout<<"Pilih?";cin>>pilih2;

		if (pilih2==1){
			goto gauss;
		}
		else if (pilih2==2){
			goto gaussj;
		}
		else if (pilih2==3){
			goto invers;
		}
		else if (pilih2==4){
			goto cramer;
		}
		else {
			goto menu;
		}
	}
	else if (pilih==2){
		goto determinan;
	}
	else if (pilih==3){
		goto invers;
	}
	else {
		return 0;
	}

    //alamat gauss
    gauss :
    {
        int n,i,j,k;
        cout.precision(4);
        cout.setf(ios::fixed);
        cout<<"\nInput banyak persamaan:\n"; cin>>n;

        float a[n][n+1],x[n];
        cout<<"\nInput nilai augmentented matrik perbaris :\n";
        for (i=0;i<n;i++)
        {
            for (j=0;j<=n;j++)
            {
                cin>>a[i][j];
            }
        }
        for (i=0;i<n;i++)
        {
            for (k=i+1;k<n;k++)
            {
                if ((a[i][i])<(a[k][i]))
                {
                    for (j=0;j<=n;j++)
                    {
                        float temp=a[i][j];
                        a[i][j]=a[k][j];
                        a[k][j]=temp;
                    }
                }
            }
        }
        cout<<"\n Kondisi matriks :\n";

        for (i=0;i<n;i++)
        {
            for (j=0;j<=n;j++)
            {
                cout<<a[i][j]<<setw(16);
            }

            cout<<"\n";
        }
        for (i=0;i<n-1;i++)
        {
            for (k=i+1;k<n;k++)
            {
                float t=a[k][i]/a[i][i];
                for (j=0;j<=n;j++)
                    a[k][j]=a[k][j]-t*a[i][j];
            }
   	 }

   	 cout<<"\n\nMatriks Gauss eliminasi:\n";
   	 for (i=0;i<n;i++)
   	 {
        for (j=0;j<=n;j++)
        {
            cout<<a[i][j]<<setw(16);
        }
        cout<<"\n";
  	  }
  	  for (i=n-1;i>=0;i--)
  	  {
  	      x[i]=a[i][n];

  	      for (j=i+1;j<n;j++)
  	      {
            if (j!=i)
            {
                x[i]=x[i]-a[i][j]*x[j];
            }
          }

          x[i]=x[i]/a[i][i];
        }

   	 cout<<"\n Hasil Matriks:\n";
   	 for (i=0;i<n;i++)
     {
          cout<<x[i]<<endl;
     }

     return 0;
}

	//alamat gauss jordan
	gaussj :
	{
	    float a[M][M];;
        int n = 3, flag = 0, baris, kolom;

        cout << "input banyak persamaan : "; cin >> baris;
        cout << "input banyak kolom pada augmented matriks : "; cin >> kolom;

        for(int i = 0; i < baris; i++)
        {
            for(int j = 0; j < kolom; j++)
            {
                cin >> a[i][j];
            }
        }

        flag = operasi(a, n);
        if (flag == 1)
        {
            flag = cek(a, n, flag);
        }

        cout << "hasil augumented matriks  : " << endl;
        cetak_matriks(a, n);
        cout << endl;
        cetak_hasil(a, n, flag);

        return 0;
	}

	//alamat invers
	invers:
	{
        int n,i,j,k,l;
        float a[20][20];

        cout <<endl<<"Masukkan ordo Matriks A (n x n)"<<endl;
        cout <<"n : "; cin >>n;
        cout <<endl;

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                cout <<"A("<<i<<","<<j<<") : ";
                cin >>a[i][j];
            }
        }

        cout <<endl;

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++)
            {
                cout <<"    "<<a[i][j];
            }

            cout <<endl;
        }

        for (j=n+1;j<=n+n;j++)
        {
            i=j-n;
            a[i][j]=1;
        }

        for (j=n+1;j<=n+n;j++)
        {
            for (i=1;i<=n;i++)
            {
                if (i!=(j-n)) a[i][j]=0;
            }
        }

        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n+n;j++)
            {
                if (i!=j)
                {
                    a[i][j]=a[i][j]/a[i][i];
                }
            }

            for (j=1;j<=n+n;j++)
            {
                if (i==j)
                {

                }
            }
            for (l=1;l<=n;l++)
            {
                if (i!=l)
                {
                    for (j=i+1;j<=n+n;j++)
                    {
                        a[l][j]=a[l][j]-(a[i][j]*a[l][i]);
                    }
                }
            }

            for (k=1;k<=n;k++)
            {
                if (i!=k)
                {
                    a[k][i]=0;
                }
            }
        }

        cout <<"Maka invers dari matriks A adalah : "<<endl;
        cout.precision(4);
        cout.setf(ios::fixed);

        for (i=1;i<=n;i++)
        {
            for (j=n+1;j<=n+n;j++)
            {
                cout <<"    "<<a[i][j];
            }
            cout <<endl;
        }
            system("PAUSE");
            return EXIT_SUCCESS;
	}

	// alamat determinan
	determinan :
	{
        int n, i, j;
        int matriks[10][10];
        cout << "Input ukuran Matriks:\n"; cin >> n;
        cout << "Isi Elemen Matriks:\n";

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cin >> matriks[i][j];
            }
        }

        cout<<"Nilai Matriks:"<<endl;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                cout << matriks[i][j] <<" ";
            }

            cout<<endl;
        }

        cout<<"Hasil Determinan Matriks "<< determinan(matriks, n);

        return 0;
	}

	//rumus cramer
	cramer :
    {
        cout<<"Masuk matriks 3x3 perbaris\n";
        cout<<"Berikan spasi setiap imputan \n";
        cout<<"\nContoh:\n\n";
        cout<<"  3  4  5    6 -> 6 Angka bagian kanan\n";
        cout<<"  2  7  5    3 \n";
        cout<<"  1  3  4    2 \n";

        bool sahi=true;
        while(sahi)
        {
            cout<<"Masukan...\n";
            int matriks[3][3];
            int matriks1[3][1];
            int reserve[3][3];
            int det00, detr[3], sp1=0,cont=0, teen=1;
            char in;
            input(matriks, matriks1);
            eksekusi_salin(reserve, matriks);
            det00=determinan(matriks);
            while(sp1<3)
            {
                detr[cont]=salin(matriks, matriks1, sp1);
                eksekusi_salin(matriks,reserve);
                cont++;
                sp1++;
            }
            cont=0;
            while(cont<3)
            {
                cout<<"x"<<teen<<" = "<<  detr[cont]<<" /"<<det00<<endl;
                cont++;
                teen++;
            }
            cout<<"Ketik n ketika mau keluar\n";
            cin>>in;
            if(in=='n' || in=='N')
            {
                return 1;
            }
        }
        return 0;
    }
}

void input(int array[][3], int array1[][1])
{
    int baris=0, kolom=0, x=0;

    while(baris<3)
    {
        kolom=0;
        while(kolom<3)
        {
            cin>>array[baris][kolom];
            kolom++;
        }
        cin>>array1[x][0];
        x++;
        baris++;
    }
}

int determinan(int array[][3])
{
    int baris=1, kolom=1, z=0, temp=0, cont=1, x=0;

    while(x<3)
    {
        temp=temp+cont*(array[0][x]*hitung(array,baris, kolom, z));
        kolom=kolom*0;
        z=z+cont;
        cont=cont*-1;
        x++;
    }

    cout<<"\nDeterminan Matriks : "<<temp<<"\n\n";

    return temp;
}

int hitung(int array[][3], int a, int b, int c)
{
    int temp1;

    temp1=(array[a][b]*array[a+1][b+1+c])-(array[a+1][b]*array[a][b+1+c]);

    return temp1;
}

int salin(int array[][3], int array1[][1], int a)
{
    int kolom=0, temp;

    while(kolom<3)
    {
        array[kolom][a]=array1[kolom][0];
        kolom++;
    }

    int i=0, j=0;

    while(i<3)
    {
        j=0;
        while(j<3)
        {
            cout<<array[i][j]<<"  ";
            j++;
        }
        cout<<endl;
        i++;
    }

    temp=determinan(array);

    return temp;
}

void eksekusi_salin(int array[][3], int array1[][3])
{
    int baris=0, kolom=0;

    while(baris<3)
    {
        kolom=0;
        while(kolom<3)
        {
            array[baris][kolom]=array1[baris][kolom];
            kolom++;
        }
        baris++;
    }
}
