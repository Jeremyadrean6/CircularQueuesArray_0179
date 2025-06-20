#include <iostream>
using namespace std;

class Queues
{
private:
    static const int max = 5;
    int FRONT, REAR;
    int queue_array[5];

public:
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    void insert()
    {
        int num;
        cout << "Enter a number : ";
        cin >> num;
        cout << endl;

        // cek apakah antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))
        {
            cout << "\nQueue overflow\n "; // 1.a
            return;                        // 1.b
        }

        // 2. cek apakah antrian kosong
        if (FRONT == -1)
        {
            FRONT = 0; // 2.a
            REAR = 0;  // 2.b
        }
        else
        {
            // jika REAR berada di posisi terakhir Array, kembali ke awal array
            if (REAR == max - 1)
                REAR = 0;
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;
   
    }

    void remove (){
        // cek apakah antrian kosng 
        if (FRONT == -1 ){
            cout << "Queue underflow\n ";
            return;
        }
        cout << "\nThe.element deleted from the queue is : " << queue_array[FRONT] << "\n";

        // Cek jika antrian hanya memiliki satu elemen
        if (FRONT == REAR)
        {
            FRONT = -1;
            REAR = -1;  
        }
        else
        {
            // jika elemen yang dihapus berada di posisi terakhir Array, kembali ke awal array
            if (FRONT == max - 1)
                FRONT = 0;
            else
                FRONT = FRONT + 1;
        }
    }
    void display()
    {
        int FRONT_position = FRONT;
        int REAR_position = REAR;

        // Cek apakah anrian kosong
        if (FRONT == -1)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "\nElements in the queue are...\n";

        // Jika FRONT_position, iterasi dari FRONT hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
        }
        else
        {
            // Jika FRONT_position, iterasi dari FRONT hingga akhir array
            while ( FRONT_position <= max -1)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            // Kemudian iterasi dari awal array hingga REAR
            FRONT_position = 0;

            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << " ";
                FRONT_position++;
            }
            cout << endl;
        }
    }

};

