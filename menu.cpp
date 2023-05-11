//sheryar ali
//22i-2623

#include "header.h"


void carParkingMenu(vector<int>  regNo ,vector<int>  arrTime , vector<int>  slotNo, Car* cars , int numCars);
void displaycarDetails(Car* cars, int numberOfCars);
void sampleData (Car* cars , int numCars);
   void updateSlotNumber(vector<int> slotNo, int oldSlotNUM , int newSlotNum ,int numberOfCars);
   void searchCar(int regNum, Car* cars , int numberOfCars);
   void removeallCars( Car* cars , int numberCars , vector<int>&  regNo , vector<int>&  arrTime , vector<int>&  slotNo);
void removeCarbySlotNo (int slotNum , int numberOfCars , vector<int>&  regNo ,vector<int>&  arrTime , vector<int>&  slotNo);
void passingValuestoVectors(vector<int>& regNo ,vector<int>& arrTime , vector<int>& slotNo  , Car* cars , int numCars);

int main()
{
     int numCars =10;
    Car* cars = new Car[numCars];

    int choice;

     //creating vectors to store all details
   vector<int> regNo;
   vector<int> arrTime ;
   vector<int> slotNo;

    sampleData (cars , numCars);

  
passingValuestoVectors( regNo, arrTime ,slotNo  ,cars ,  numCars);


    while (true)
    {
        cout<<"=== Welcome to Car Parking Management System ==="<<endl;
        cout << "Press '1' to continue to Car Parking Menu" << endl;
        cout << "Press '2' to exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:{
            cout<<"Enter number of Cars: ";
            cin>>numCars;
            carParkingMenu( regNo, arrTime , slotNo, cars ,numCars);
             break;
        }          
        case 2:
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}

void carParkingMenu( vector<int> regNo ,vector<int> arrTime , vector<int> slotNo,Car* cars , int numCars) {
    int choice;

   int newregNo;
   int newarrTime;
    int newslotNo;
    int remslotNO;
    int remregNo;
    int remarrTime;
    int oldSlotNUM;
    int newSlotNum;
    char removeChoice;
    int searchregNo;
   

    while (true) {
        cout<<"=== Welcome to Car Parking Menu ==="<<endl;
        cout << "Press '1' to add car" << endl;
        cout << "Press '2' to remove car by slot" << endl;
        cout << "Press '3' to update car slot" << endl;
        cout << "Press '4' to remove all cars" << endl;
        cout << "Press '5' to search car by registration number" << endl;
        cout << "Press '6' to get total parked cars" << endl;
        cout << "Press '7' to display all cars" << endl;
        cout << "Press '8' to exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
            {
                 displaycarDetails(cars, numCars);
                cout << "Adding  car to parkinglot" << endl;
                numCars++;
                cout<<"Enter registration number: ";
                cin>>newregNo;
                cout<<"Enter arrival time: ";
                cin>>newarrTime;
                cout<<"Enter slot number: ";
                cin>>newslotNo;
                cars[numCars].setArrTime(newarrTime);
                cars[numCars].setSlotNo(newslotNo);
                cars[numCars].setRegNo(newregNo);
                sampleData (cars , numCars);
                break;
            }
                
            case 2:
            {
                cout << "Removing car by slot" << endl;
                cout<<"<<=============================>> "<<endl;
                displaycarDetails(cars, numCars);
                cout<<"<<=============================>> "<<endl;
                cout<<"Enter slot number: ";
                cin>>newSlotNum;

             removeCarbySlotNo (newSlotNum , numCars , regNo ,arrTime , slotNo);

                break;
            }
                

            case 3:
            {
                 cout << "Removing car by slot" << endl;
                 cout<<"<<=============================>> "<<endl;
                     displaycarDetails(cars, numCars);
                cout<<"<<=============================>> "<<endl;
                 cout<<"\n Enter the old slot number: ";
                 cin>>oldSlotNUM;
                cout<<"Enter updated slot number: ";
                cin>>newSlotNum;

             updateSlotNumber( slotNo, oldSlotNUM , newSlotNum , numCars);
             

                break;

            }
               
            case 4:
            {
                cout << "Do you want to remove all cars : 'Y' " << endl;
                cin>>removeChoice;
                if (removeChoice == 'Y' || removeChoice == 'y')
                {
                    removeallCars( cars , numCars ,regNo ,  arrTime ,slotNo);
                    cout << "Removing all cars" << endl;
                   
                }
                else 
                    cout << "Not removing all cars" << endl;
                
                break;

            }
            case 5:
            {
                cout << "Searching car by registration number" << endl;
                cout<<"Enter registration number: ";
                cin>>searchregNo;
                searchCar(searchregNo, cars , numCars);
                break;

            }
            case 6:
            {
                cout << "Getting total parked cars" << endl;
                cout<<"Total parked cars are "<<numCars<<endl;
                break;

            }
            case 7:
            {
                cout << "Displaying all cars" << endl;
                displaycarDetails(cars, numCars);

                break;

            }
            case 8 :
            {
                return ;
            }
                    }
            }

            };



   
      void passingValuestoVectors(vector<int>& regNo ,vector<int>& arrTime , vector<int>& slotNo  , Car* cars , int numCars)
        {

          for (int i =0 ; i<numCars ; i++){

        regNo.push_back(cars[i].getRegNo());
        arrTime.push_back(cars[i].getArrTime());
        slotNo.push_back(cars[i].getSlotNo());
    }
     }


   void displaycarDetails(Car* cars, int numberOfCars){
        for (int i =0 ; i<numberOfCars ; i++){

        cout<<"\n Registeration number of car "<<i+1<<" is "<<cars[i].getRegNo()<<endl;
        cout<<"\n Arrival time of car "<<i+1<<" is "<<cars[i].getArrTime()<<endl;
        cout<<"\n Slot number of car "<<i+1<<" is "<<cars[i].getSlotNo()<<endl;
        cout<<"\n"<<endl;
    }

    }
    
    void removeCarbySlotNo (int slotNum , int numberOfCars , vector<int>& regNo ,vector<int>&  arrTime , vector<int>& slotNo){

         for (int i =0 ; i<numberOfCars ; i++){
        if(slotNum == slotNo[i]){
            slotNo.erase(slotNo.begin()+i);
            regNo.erase(regNo.begin()+i);
            arrTime.erase(arrTime.begin()+i);
        }
    }
    cout<<"\n The car with slot number "<<slotNum<<" is removed from the parking lot Successfully"<<endl;

    }

       void updateSlotNumber(vector<int>  slotNo, int oldSlotNUM , int newSlotNum ,int numberOfCars){
    for (int i =0 ; i<numberOfCars ; i++){

        if(oldSlotNUM == slotNo[i]){
    
            slotNo[i] = newSlotNum;
        }
    }
    cout<<"\n The slot number "<<oldSlotNUM<<" is updated to "<<newSlotNum<<" Successfully"<<endl;
    }

    
    void removeallCars( Car* cars , int numberCars , vector<int>& regNo , vector<int>&  arrTime , vector<int>&  slotNo)
    {
                    for (int i =0 ; i<numberCars ; i++){
                regNo.erase(regNo.begin()+i);
                arrTime.erase(arrTime.begin()+i);
                slotNo.erase(slotNo.begin()+i);
            }

        cout<<"\n All cars are removed from the parking lot Successfully"<<endl;

    }

    void searchCar(int regNum, Car* cars , int numberOfCars)
    {
          for (int i =0 ; i<numberOfCars ; i++){
     
     //condition to check if resgisteration num is equal to vector registeration num
     //using loop

         for (int j =0 ; j<numberOfCars ; j++){
           if (regNum == cars[j].getRegNo()){
               cout<<"The car is found"<<endl;
               cout<<"The arrival time is "<<cars[j].getArrTime()<<endl;
               cout<<"The slot number is "<<cars[j].getSlotNo()<<endl;
           }
       }
   
    }
    }

    void sampleData (Car* cars , int numCars){

        //sample data for cars regno
        for (int i =0 ; i<numCars ; i++){
        cars[i].setRegNo(i+1);

        }
        //sample data for cars arrival time
        for (int j =0 ; j<numCars ; j++){
            cars[j].setArrTime(j+1);
        }
        //sample data for cars slot number
        for (int k =0 ; k<numCars ; k++){
            cars[k].setSlotNo(k+1);
        }
    }