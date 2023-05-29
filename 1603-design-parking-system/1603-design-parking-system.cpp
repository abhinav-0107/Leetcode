class ParkingSystem {
public:
    vector<int>max;
    ParkingSystem(int big, int medium, int small) {
        max.push_back(big);
        max.push_back(medium);
        max.push_back(small);
    }
    
    bool addCar(int carType) {
        if(max[carType-1]){
            max[carType-1]--;
            return true;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */