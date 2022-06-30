/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            bar.num += 1;                    //2a)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()





struct Cat
{
    Cat();
    std::string type;
    int numEars;
    float dailyFoodIntake {5.4f};
    std::string furColor = "brown";
    double tailLength = 5.3432;
    

    struct Kitten 
    {    
        int birthYear {2020};
        Kitten();
        std::string disposition;
        int numLegs = 4;
        int numWhiskers {24};
        std::string catBreed = "Tabby";       

        void feed(bool isHungry);
        void pet(bool isAffectionate, float minutesToPet);
        void roamNeighborhood(bool rainyWeather, float avgCatTravels = 20.f);
        void roll(int numRolls, int happyIdxOutOfTen = 0)
        {
            numRolls = 0;
            while (numRolls < 100)
            {  
                for(happyIdxOutOfTen = 1; happyIdxOutOfTen <= 10; ++happyIdxOutOfTen)
                {
                    numRolls+=10;
                    std::cout << "Kitten rolls " << numRolls  << " times on the floor."  << std::endl; 
                    
                }
            break;
            }
            std::cout << "Kitten is feeling too dizzy to roll anymore." << std::endl;   
            
        }
    };

    void scratchFurniture(bool isChair = false, int numberOfFurniture = 10);
    void makeNoise(bool foodBowlEmpty = true);
    bool sleep(bool isAsleep = true);
    void typicalCat(std::string, int, float);
    void gainWeight(int weight, int overweight = 20) 
    {
       
        while (weight < overweight)
            {
                for(weight = 10; weight <= 20; ++weight)
                {
                dailyFoodIntake += 1.f;
                std::cout << "Kitty eating more and more every day" << std::endl;
                }
            }
        std::cout << "Kitty on a diet." << weight  << std::endl;
    }

    Kitten kittenJunior; 
};

Cat::Cat()
: type("domesticated"), numEars(2), dailyFoodIntake(5.1f)
{
        std::cout << "A typical " << type << " cat  has " << numEars << " ears and eats one " << dailyFoodIntake << " oz can of cat food a day." << std::endl;
}

Cat::Kitten::Kitten() 
: disposition("nice"), numWhiskers(26)
{
    std::cout << "A " << disposition << " kitten with " << numWhiskers << " whiskers being constructed!" << std::endl;
}

void Cat::Kitten::feed(bool isHungry)
{
    float singlePortion = 0;
    if(isHungry)
    {
        singlePortion = 6.f;
    }
    std::cout << "Kitty can have " << singlePortion << " oz of food." << std::endl;
    
}

void Cat::Kitten::pet(bool isAffectionate, float minutesToPet)
{
    if(isAffectionate)
    {
        minutesToPet = 20.f;
    }
}
void Cat::Kitten::roamNeighborhood(bool rainyWeather, float avgCatTravels)
{
    float milesTraveled;
    if(!rainyWeather)
    {
        milesTraveled = avgCatTravels * 2;
    }
}
void Cat::scratchFurniture(bool isChair, int numFurnitureDestroyed)
{
    if(!isChair)
    {
        numFurnitureDestroyed += 1;
    }
        
}
void Cat::makeNoise(bool foodBowlEmpty)
{
    std::string noise = "";
    if(foodBowlEmpty)
    {
        noise = "meow";

    }
    else 
    {
        noise = "purr";
    }
    std::cout << "Cat goes: " << noise << std::endl;
}

struct Time
{
    int year = 2022, 
    month = 6, 
    day = 23, 
    hour = 7, 
    minute = 1, 
    second = 5;
    bool isPM = true;
};

bool Cat::sleep(bool isAsleep)
{
    Time startTime, endTime;
    startTime.hour = 0;
    endTime.hour = 5;
    
    if( startTime.hour > 0 && 
        startTime.isPM == false && 
        endTime.hour < 5 && 
        endTime.isPM == false )
    {
        return isAsleep;
    }
    return !isAsleep;
}

struct Range
{
    Range();
    int numOfRack;
    int maxTempOven = 450;
    std::string fuelType = "gas";
    int numOfTops;
    int width = 36;

    struct RangeControls
    {
        int date_;
        RangeControls() : date_(20220628) {}
        std::string clockSettingOption {"24hrs"};
        int daysLeft;
        std::string controlPanelColor = "chrome";
        int controlPanelWidth = 24;
        bool supportsWifi = true;
        bool isAnalog = false;
        int maxKnobTurned = 10;

        void printDaysLeft(int warrantyBy);
        void informCurrentTime(bool timeUpdated);
        void indicateRepairDate(std::string date, bool needsRepair);
        bool selfCleans(bool heavyCleaning = true, std::string setting = "");
        void turnUpTemp(int ovenTemp = 350)
        {
            while(ovenTemp <= 355)
            {
                int degreeKnobTurned;
                for(degreeKnobTurned = 0; degreeKnobTurned <= maxKnobTurned; ++degreeKnobTurned)
                {
                    ovenTemp += 1;
                    std::cout << "Increasing the oven temperature." << std::endl;   
                }
            break;
            }
            std::cout << "Warning. Oven too hot." << std::endl;  
        }  
    };

    void consumeFuel(std::string, int);
    void breaksDown(int ageOfHeatingElement);
    void heatsTheKitchen(int, int);
    void getBigger(int price)
    {
        while(numOfTops < 10)
        {
            for(price = 1500 ; price <= 1502; ++price)
            {
                numOfTops += 1;
                std::cout << "Pricier ovens have more cooktops." << std::endl;   
            }
        break;
        }
        std::cout << "Ovens do not come in a bigger size." << std::endl;   
    }

    RangeControls updatedSettings; 
};


Range::Range() 
: numOfRack(3), numOfTops(6)
{
    std::cout << "Range with " << numOfRack << " oven racks and " << numOfTops << " cooktops being constructed" << std::endl;
}

void Range::consumeFuel(std::string fuelSource = "electric", int energyEfficiency = 65)
{
    std::cout << "On average," << fuelSource << " convection oven has " << energyEfficiency << " percent cooking energy efficiency." << std::endl;
}

void Range::breaksDown (int ageOfHeatingElement)
{
    if( ageOfHeatingElement >= 50) 
    {
        std::cout << "It'll break down within a year." << std::endl;
    }
    else if( ageOfHeatingElement> 10 && ageOfHeatingElement < 50)
    {
        std::cout << "Range can be used for a few more years." << std::endl;
    }
}

void Range::heatsTheKitchen(int durationOperated, int ovenTemp)
{
    int kitchenTemp = 70;
    if(durationOperated > 0 && ovenTemp > 0)
    {
        kitchenTemp = kitchenTemp + (ovenTemp / 100) * (durationOperated/4);
    }
    std::cout << "Currently kitchen temp is " << kitchenTemp << " due to oven use." << std::endl;
}

void Range::RangeControls::printDaysLeft(int warrantyBy = 20220630)
    {
        daysLeft = warrantyBy - date_;
        std::cout << "You have: " << daysLeft << " days left until your warrnty expires." << std::endl;
    }

void Range::RangeControls::informCurrentTime (bool timeUpdated)
{
    std::string updatedTime = "17:00:00", currentTime = "12:00:00";
    if(timeUpdated)
    {
        std::cout << "Time updated to: " << updatedTime << std::endl;
    }
    std::cout << "Current time is: " << currentTime << std::endl;

}
void Range::RangeControls::indicateRepairDate (std::string date, bool needsRepair)
{
    if(needsRepair)
    {
        std::cout << "Range needs repair by " << date << std::endl;
    }
    else
    {
        std::cout << "Range In Good Shape" << std::endl;
    }
    
}
bool Range::RangeControls::selfCleans (bool heavyCleaning, std::string setting)
{
    if( setting == "heavy")
    {
        return heavyCleaning;
    }
    return !heavyCleaning;
} 


struct ShoppingCart 
{
    ShoppingCart ();
    std::string cartMaterial = "aluminum";
    int numWheels;
    std::string colorHandle = "red";
    float cartWidth;
    std::string cartStore = "Albertsons";

    bool carryGrocery (bool badWheels = false, float weightLimit =  40.2f);
    bool rollsDownHill (bool steepHill, bool fast);
    void isParked (int, std::string, int);
    void rollDownFaster(int degreeHill)
    {
        while(degreeHill > 0 && degreeHill < 90)
        {
            ++degreeHill;
            std::cout << "Shopping cart rolling down faster and faster." << std::endl;
        }
        std::cout << "Shopping cart probably not moving much." << std::endl;
    }
};

ShoppingCart::ShoppingCart()
: numWheels(4), cartWidth(1.1f)
{
    std::cout << cartWidth << " wide shopping cart with " << numWheels << " wheels being constructed!" << std::endl;
}

bool ShoppingCart::carryGrocery (bool badWheels, float weight)
{
    if(badWheels && weight <= 40.2f)
    {
        return true;
    }
    return false;
}
bool ShoppingCart::rollsDownHill (bool steepHill, bool fast)
{
    if(steepHill)
    {
        return fast;
    }
    return !fast;
}
void ShoppingCart::isParked(int numCartsInCorral = 1, std::string  cartLocation = "corral", int totalNumCarts = 100)
{
    int missingCarts = totalNumCarts - numCartsInCorral;
    if(cartLocation == "corral")
    {
        std::cout << "Cart is safely parked in " << cartLocation << std::endl;
    }
    std::cout << missingCarts << " cart(s) need(s) to be moved to the cart coarral." << std::endl;
}

struct Wind
{
    Wind();
    double speed = 3.4234898;
    std::string direction = "North West";
    std::string definition = "movement in air molecules";
    std::string cause = "difference in gas density";
    std::string use;
    

    void transportSeeds (int, std::string, int);
    bool turnTurbines (std::string, float gust = 34.2f);
    void helpBirdTravel (std::string direction2, bool birdFly, float gust = 34.2f);
    void beaufortScale(int gust, int highParam)
    {
        int lowerParam = 1;
        while (highParam <= 64)
        {
            if (gust > lowerParam  && gust < highParam )
            {
                lowerParam += 6;
                std::cout << "Within Beaufort scale." << std::endl;
            }
            std::cout << "Gust: " << gust << std::endl;
            break;
        }
        std::cout << "Hurricane alert. Past the top end of the Beaufort scale." << std::endl;
    }
}; 

Wind::Wind()
: use("wind energy")
{
    std::cout << "Wind being constructed to create " << use << std::endl;
}

void Wind::transportSeeds (int numSeeds, std::string treeName, int milesTraveled)
{
    if(treeName == "poplar")
    {
        numSeeds = 25000000;
        milesTraveled = 20;
    }
    std::cout << "Strong wind can disperse " << numSeeds << " " << treeName << " seeds up to " << milesTraveled << " miles." << std::endl;
}

bool Wind::turnTurbines (std::string direction1, float gust)
{
    if(direction1 == "North West" && gust > 80.f)
    {
        return true;
    }
    return false;
}
void Wind::helpBirdTravel (std::string direction2, bool birdFly, float gust)
{
    std::string birdDirection = "West";
    if(direction2 == birdDirection && gust < 100)
    {
        birdFly = true;
    }
}

struct PlaneWings  
{
    PlaneWings();
    int maxFlex = 28;
    int fuelCarried = 23;
    int numOfAilerons = 4;
    int numEngines;
    float wingSpan;

    void generateLift(bool, std::string);
    bool reduceDrag(float tailwind = 10.f);
    void lowersLandingSpeed(int drag, bool landed =  false, float landingSpeed = 30.2f);
    void flex(int flex = 10)
    {
        while (flex < maxFlex)
        {
            for (wingSpan = 200; wingSpan <= 202; ++wingSpan)
            {
            flex += 1;
            std::cout << "Longer the wing, more it can flex." << std::endl;   
            }
        }
        std::cout << "Wing broken when flexed over 28ft." << std::endl;
    }
};

PlaneWings::PlaneWings()
: numEngines(4), wingSpan(195.3f)
{
    std::cout << "Jumbo jet wings span " << wingSpan << " feet and have "<< numEngines << " engines attached to them." << std::endl;
}

void PlaneWings::generateLift (bool upwardForce, std::string airDirection)
{   
    std::string planeStatus = "stays on the ground";
    if (airDirection == "down" && upwardForce)
    {
        planeStatus = "goes up";
    }
    std::cout << "When the air goes " << airDirection << " the upward force creates lift and the plane " << planeStatus << std::endl;
}

bool PlaneWings::reduceDrag (float tailwind)
{
    if(tailwind < 10.f) 
        return true;
    return false;
}
void PlaneWings::lowersLandingSpeed (int drag, bool landed, float landingSpeed )
{
    if(!landed)
    {
        landingSpeed -= drag;
    }
}

struct LandingGear
{
    LandingGear();
    float wheelDiameter = 3.21f;
    int numWheels = 8;
    float weightOfNose = 34.2f;
    int numMainLandingGear;
    float maxTirePressure = 200.1f;

    int reduceLandingImpact (float tirePressure = 250.2f, int landingSpeed = 20);
    bool preventFuselageHittingGround (bool retractLandingGear = false);
    void toggleLandingGear (bool, std::string);
    void inflate(float currentPressure)
    {  
        while  ( currentPressure <= maxTirePressure)
        {
            std::cout << "Tire pressure should ideally reach " << maxTirePressure << std::endl;
            break;
        }
        std::cout << "Tires burst." << std::endl;
    }
};

LandingGear::LandingGear()
: numMainLandingGear(16)
{
    std::cout << numMainLandingGear << " landing gear being constructed!"  << std::endl;
}

int LandingGear::reduceLandingImpact (float tirePressure, int landingSpeed)
{
    int calculateImpact = 3 * landingSpeed;
    if(tirePressure > 200) 
    {
        return calculateImpact;  
    }
    return landingSpeed;
}

bool LandingGear::preventFuselageHittingGround (bool retractLandingGear)
{
    if(!retractLandingGear)
    {
         return true;
    }
    return false;
}

void LandingGear::toggleLandingGear (bool takeOff, std::string landingGearStatus)
{
    if(takeOff && landingGearStatus == "extended")
    {
        std::cout << "Warning! Landing gear postion: " << landingGearStatus << std::endl;
    }
    else if(takeOff && landingGearStatus == "retracted")
    {
         std::cout << "Safe flight. Landing gear position: " << landingGearStatus << std::endl;
    }
    else if(!takeOff && landingGearStatus == "extended")
    {
        std::cout << "Ready to land. Landing gear position: " << landingGearStatus << std::endl;
    }
    else if(!takeOff && landingGearStatus == "retracted") 
    {
        std::cout << "Warning! Landing gear postion: " << landingGearStatus << std::endl;
    }
}

struct PlaneTail 
{
    PlaneTail();
    float weightLowerRudder;
    float lengthOfLowerRudder = 62.f;
    std::string auxPower = "helps plane turn";
    float weigtUpperRudder;
    float heightUpperRudder = 62.f;
    int powerConsumed = 1;
    
    void runPowerUnit(std::string);
    void consumePower(bool);
    void turnPlane(bool lowerRudderOpen = true);
    void cancelRightTurn( int degreeOfrightTurnInducedByDrag, int rudderDegree)
    {
        while (degreeOfrightTurnInducedByDrag <= 90)
        {
            for(degreeOfrightTurnInducedByDrag = 1 ; degreeOfrightTurnInducedByDrag <= 90; ++degreeOfrightTurnInducedByDrag )
            rudderDegree -= degreeOfrightTurnInducedByDrag;
            std::cout << "Rudder coordinates the plan to turn"<< std::endl;
        }
        std::cout << "Emergency landing! Strong drag."<< std::endl;
    }  
};

PlaneTail::PlaneTail()
: weightLowerRudder(1000.1f), weigtUpperRudder(1000.1f)
{   
    std::cout << "Jumbo jet's tail weighs over " << weightLowerRudder + weigtUpperRudder << " lbs."<< std::endl;
}

void PlaneTail::runPowerUnit (std::string planeStatus)
{ 
    bool powerUnitRunning = false; 
    if(planeStatus == "on the ground")
    {
        powerUnitRunning = true;
    }
    std::cout << "The auxilary power unit runs while the aircraft is " << planeStatus << std::endl; 
}

void PlaneTail::consumePower (bool engineRunning)
{
    if (engineRunning) 
    {
        std::cout << "Engine running" << "\n";
        powerConsumed += 1; 
    }
    std::cout << "Small engine not running" << std::endl;
    
}

void PlaneTail::turnPlane (bool lowerRudderOpen)
{
    bool right = false;
    if(lowerRudderOpen)
    {
        right = true; 
    }
    std::cout << "Stay on course" << std::endl;
}

struct PassengerCabin
{
    PassengerCabin();
    int numSeats = 416;
    std::string seatMaterial = "leather";
    int numToilets = 4;
    float weightCarryOn = 1;
    int aisleWidth;

    void carryPassengers(int numPassengers = 200);
    void carryToilets(int numOfToilets, int numPassengers);
    void blanketsAlert(int numPassengers, int numBlankets);
    void supplyJuice( int numPassengers, int juiceConsumed)
    {
        int juiceInStock = 0;
        auto np = numPassengers;
        while (juiceConsumed <= 2)
        {
            for(np = 1; np <= 2; ++np)
            {
                juiceInStock++; 
                std::cout << "Each passenger may have 1+ juice box." << std::endl;
            }
        break;
        }
        std::cout << "Offer passenger something else to drink." << std::endl;
    }
    
};

PassengerCabin::PassengerCabin()
: aisleWidth(1)
{   
    std::cout << "Passenger cabin typically has "  << aisleWidth * 2 << " " << aisleWidth << "ft wide aisles." << std::endl;
}

void PassengerCabin::carryPassengers (int numPassengers)
{
    std::cout << "Carrying: " << numPassengers << " passengers"<< std::endl;
}

void PassengerCabin::carryToilets (int numOfToilets, int numPassengers)
{
    std::cout << "One toilet allocated per " << numPassengers / numOfToilets << " passengers." << std::endl;  
}

void PassengerCabin::blanketsAlert (int numPassengers, int numBlankets)
{
    if(numPassengers < numBlankets)
    {
        std::cout << "Carrying: " << numBlankets << "blankets" << std::endl;
    }
    std::cout << "Stock " << (numPassengers - numBlankets) << " more blankets at least!" << std::endl;
}

struct Fuselage
{
    Fuselage();
    float thicknessFuselageWall = 24.2f;
    int weightExteriorPaint = 595;
    std::string planeMaterial = "aluminum";
    float diameterFuselage;
    float weightFuselage = 234.4f;

    void formsPlaneStructure (float fuselageDiameter = 234.3f);
    bool keepsHeatOut (std::string fuselageMaterial);
    void storeCargo (float);
    void painExterior(int paintWeight, double mainDiameter)
    {
        while (paintWeight < 600)
        {
            for(paintWeight = 1; paintWeight < 600; ++paintWeight)
            {
                mainDiameter += 1.11111;
                std::cout << "More paint adds to the resulting diameter of the fuselage." << std::endl;
            }
        break;      
        }
        std::cout << "Not up to code. Too much paint." << std::endl;
    }
};

Fuselage::Fuselage()
: diameterFuselage(20.f)
{
    std::cout << "The typical fuselage diameter is " << diameterFuselage << "ft." << std::endl;
}

void Fuselage::formsPlaneStructure (float fuselageDiameter)
{
    float planeBodyWidth = 20.f;
    float thicknessExteriorPaintAdds = 1.f;
    planeBodyWidth = fuselageDiameter + thicknessExteriorPaintAdds; 
}


bool Fuselage::keepsHeatOut (std::string fuselageMaterial)
{
    std::string materialName = "aluminum";
    return fuselageMaterial == materialName;
}

void Fuselage::storeCargo (float cargoWeight)
{
    int weightLimit = 1;
    if(cargoWeight < weightLimit)
    {
        std::cout << "Load cargo!" << std::endl;
    }
    std::cout << "Warning: cargo weight over limit!" << std::endl;
}

struct JumboJet
{
    int n;
    JumboJet() : n(0) {}
    PlaneWings rightWings;
    LandingGear wheels;
    PlaneTail lowerRudder;
    PassengerCabin touristClass;
    Fuselage lastRepair; 

    void numJumboJet (std::string airport);

    void carryPassengers(std::string destination, int numOfPassengers);
    bool fly(bool safetyInspection, double gust);
    void carryCargo(int maxWeightPermitLuggagePerPassenger);
    std::string carryFuel(int);
    void increaseAirportProfit(int airportProfit, int flightsPerDay)
    {
        while (flightsPerDay < 136)
        {
            for (flightsPerDay = 1; flightsPerDay < 136; ++flightsPerDay)
            {
                airportProfit += 100;
                std::cout << "Our airport is growing." << std::endl;
            }
        break;
        }
        std::cout << "Excessive maintenance cost. The cons outweigh the pros." << std::endl;
    }
}; 

void JumboJet::numJumboJet(std::string airport = "Burlington")
{
    std::cout << "Currently " << n << " jumbo jet(s) available at " << airport << " airport." << std::endl;
}

void JumboJet::carryPassengers(std::string destination, int numOfPassengers)
{
    int precipitation = 0;
    int windInBeaufort = 0;
    std::string safeWeather = (precipitation > 0 && windInBeaufort > 11)? "unsafe": "safe";
    if(safeWeather == "unsafe")
    {
        std::cout << "Flight canceled due to " << safeWeather << " weather condition." << std::endl; 
    }
    std::cout << "Carrying " << numOfPassengers << " passengers to " << destination << std::endl;
}

bool JumboJet::fly(bool safetyInspection, double gust)
{
    return safetyInspection && gust < 40; 
}

void JumboJet::carryCargo(int maxWeightPermitLuggagePerPassenger)
{
    std::string checkWeight = (maxWeightPermitLuggagePerPassenger <= 1) ?  "pass": "fail";
    if(checkWeight == "pass")
    {
        std::cout << "Load cargo" << std::endl;
    }
    else if(checkWeight == "fail")
    {
        std::cout << "Do not load cargo" << std::endl;
    }
}

std::string JumboJet::carryFuel(int numTanks)
{
    std::string maxFuelInGal = "";
    if(numTanks == 7) 
    {
        return maxFuelInGal = "54000";
    }
    return maxFuelInGal = "must be under 54000";
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    Example::main();
    std::cout << "good to go!" << std::endl;

    Cat Mittens;
    
    Mittens.makeNoise(true);
    Mittens.scratchFurniture(false, 10);
    Mittens.sleep(true);
    Mittens.gainWeight(10, 20);

     std::cout << "Mittens has a "<< Mittens.tailLength << " inch long " << Mittens.furColor << " tail!" <<std::endl;
    
    
    Cat::Kitten MittensJunior;
    
    MittensJunior.feed(true);
    MittensJunior.pet(true, 20);
    MittensJunior.roamNeighborhood(false, 30);
    MittensJunior.roll(97, 6);
    
    std::cout << "Mittens Junior is "<< (2022 - MittensJunior.birthYear) << " year old " << MittensJunior.catBreed <<std::endl;

    
    Range myRange;

    myRange.consumeFuel("electric", 65);
    myRange.breaksDown(70);
    myRange.heatsTheKitchen(7, 420);
    myRange.getBigger(1501);
    
    std::cout << "My range has a "<< myRange.fuelType << " powered oven that reaches up to " << myRange.maxTempOven << " F in temp." << std::endl;

    Range::RangeControls specialFeature;
    specialFeature.printDaysLeft(20220630);

    
    Range::RangeControls backControls;

    backControls.informCurrentTime(false);
    backControls.indicateRepairDate("July 25th 2022", true);
    backControls.selfCleans(false, "light");
    backControls.turnUpTemp(350);

    std::cout << "The most popular model is "<< backControls.controlPanelColor << " with its cotrol panel width of " << backControls.controlPanelWidth << "." << std::endl;
    
    ShoppingCart myCart;

    myCart.carryGrocery(false, 24.f);
    myCart.rollsDownHill(false, false);
    myCart.isParked(60, "unknown", 100);
    myCart.rollDownFaster(80);

    myCart.cartStore = "Costco";

    std::cout << "The shopping carts at "<< myCart.cartStore << " have " << myCart.numWheels << " wheels and are made of " << myCart.cartMaterial << "." << std::endl;

    
    Wind westerlies;

    westerlies.transportSeeds(10, "poplar", 10);
    westerlies.turnTurbines("North West", 90.f);
    westerlies.helpBirdTravel("West", false, 80);
    westerlies.beaufortScale(10, 64);

     std::cout << "Wind defined as "<< westerlies.definition << " mainly occurs due to " << westerlies.cause << "." << std::endl;

    PlaneWings DeltaAirWings;

    DeltaAirWings.generateLift(true, "down");
    DeltaAirWings.reduceDrag(10.f);
    DeltaAirWings.lowersLandingSpeed(10, false, 50);
    DeltaAirWings.flex(26);

     std::cout << "The jumbo jet has a wingspan of "<< DeltaAirWings.wingSpan << " ft and " << DeltaAirWings.numEngines << " engines are attached to the lower side of the wings." << std::endl;

    LandingGear noseLandingGear;
    
    noseLandingGear.reduceLandingImpact(250.2f, 20);
    noseLandingGear.preventFuselageHittingGround(false);
    noseLandingGear.toggleLandingGear(true, "retracted");
    noseLandingGear.inflate(200.f);

     std::cout << "The nose landing gear has  "<< noseLandingGear.numMainLandingGear/4 << " wheels and the pressure in the tires is about " << noseLandingGear.maxTirePressure << " psi." << std::endl;

    PlaneTail DeltaAirTail;

    DeltaAirTail.runPowerUnit("on the ground");
    DeltaAirTail.consumePower(false);
    DeltaAirTail.turnPlane(false);
    DeltaAirTail.cancelRightTurn(80, 70);

    std::cout << "The tip of the tail fin is  "<< DeltaAirTail.heightUpperRudder << " above the ground." << std::endl;
    
    PassengerCabin touristClass;

    touristClass.carryPassengers(200);
    touristClass.carryToilets(12, 400);
    touristClass.blanketsAlert(200, 180);
    touristClass.supplyJuice(29, 2);

    touristClass.seatMaterial = "polyester";

    std::cout << "The passenger cabin has two  "<< touristClass.aisleWidth << " aisles and  normally carries a maximum of " << touristClass.numSeats << " people." << std::endl;
    
    Fuselage DeltaAirFuselage;

    DeltaAirFuselage.formsPlaneStructure(234.3f);
    DeltaAirFuselage.keepsHeatOut("aluminum alloy");
    DeltaAirFuselage.storeCargo(1.f);

    DeltaAirFuselage.planeMaterial = "aluminum alloy";
    DeltaAirFuselage.painExterior(620, 1.1);

    std::cout << "Much of the 747 is made from  "<< DeltaAirFuselage.planeMaterial << " covered with " << DeltaAirFuselage.weightExteriorPaint << " lbs of exterior paint." << std::endl;
    
    JumboJet Delta;

    Delta.carryPassengers("Tampa", 100);
    Delta.fly(true, 30);
    Delta.carryCargo(1);
    Delta.numJumboJet("Rutland");
    Delta.increaseAirportProfit(100, 137);

    std::cout << "A jumbo jet carries about "<< Delta.carryFuel(7) << " gallons of fuel in 7 tanks." << std::endl;

}

