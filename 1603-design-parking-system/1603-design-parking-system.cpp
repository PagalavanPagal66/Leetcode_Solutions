class ParkingSystem {
public:
int a,b,c;
    ParkingSystem(int big, int medium, int small) {
        
        a=big;
        b=medium;
        c=small;
    }
    
    bool addCar(int ct) {
        if(ct==1 && a==0){
            return false;
        }
        if(ct==2 && b==0){
            return false;
        }
        if(ct==3 && c==0){
            return false;
        }
        if(ct==1)a--;
        if(ct==2)b--;
        if(ct==3)c--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */