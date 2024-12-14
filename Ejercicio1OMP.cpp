// Ejercicio1OMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <chrono>

using namespace std;


int main()
{

    unsigned int N;
    cout << "introduce el tamaño del vector" << endl;
    cin >> N;
    double timeIni, timeFin;
    double timeIniT, timeFinT;
    double timeIniBarrier, timeFinBarrier;
    double* start_times, * end_times;
    double global_start_time;
    double global_end_time;
    int num_threads;

    vector<int> x(N), y(N);

    //-----SIN USAR THREADS------
    timeIni = omp_get_wtime();
    //Secuencial
    for (int i = 1; i < N; i++) {
        x[i] = y[i - 1] * 2;
        y[i] = y[i] + i;
    }
    timeFin = omp_get_wtime();


     global_start_time=omp_get_wtime();

#pragma omp parallel num_threads(30)
    {
#pragma omp master
        {
            num_threads = omp_get_num_threads();
        start_times = new double[omp_get_num_threads()];
        end_times = new double[omp_get_num_threads()];
        timeIniBarrier = omp_get_wtime();
        
        }

        //----USANDO THREADS-----
#pragma omp critical
        {
            start_times[omp_get_thread_num()] = omp_get_wtime();

        }



#pragma omp for 
        for (int i = 1; i < N; i++) {
            //sección crítica
            x[i] = y[i - 1] * 2;
            y[i] = y[i] + i;
        }

#pragma omp critical
        {
            end_times[omp_get_thread_num()] = omp_get_wtime();

        }


 #pragma omp barrier


#pragma omp master
        {
            timeFinBarrier = omp_get_wtime();
            cout << "Tiempo de barrera: " << timeFinBarrier - timeIniBarrier << " segundos" << endl;

            for (int i = 0; i < omp_get_num_threads(); i++)
            {
                cout << "Thread " << i << ": " << end_times[i] - start_times[i] << " segundos" << endl;
            }


            delete[] start_times;
            delete[] end_times;



        }

    }
    global_end_time = omp_get_wtime();


    cout << "Con tamaño del vector: " << N << endl;
    cout << " Usando " << num_threads << " threads " << endl;
    cout << "Tiempo de ejecucion SIN threads: " << timeFin - timeIni << " segundos" << endl;
    cout << "Tiempo de ejecucion CON threads: " << global_end_time - global_start_time << " segundos" << endl;
    cout << "Diferencia de tiempo: " << (timeFin - timeIni) - (global_end_time - global_start_time) << " segundos" << endl;
}


