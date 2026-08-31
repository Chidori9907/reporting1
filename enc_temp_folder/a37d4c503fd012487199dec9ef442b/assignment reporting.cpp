#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cctype>
#include <ctime>
using namespace std;

//=======================from jiayih=======================
const int MAX_SIZE = 100;

struct Customer {
    string idCustomer;
    string nameCustomer;
    string genderCustomer;
    string phoneCustomer;
    string emailCustomer;
    string passwordCustomer;
};

struct Member {
    string idMember;
    string nameMember;
    string genderMember;
    string phoneMember;
    string emailMember;
    string passwordMember;
};

struct Staff {
    string idStaff;
    string nameStaff;
    string genderStaff;
    string phoneStaff;
    string emailStaff;
    string passwordStaff;
    string positionStaff;
};

int customerCounter = 1005;
int memberCounter = 1005;
int staffCounter = 1011;

const int MAX_CUSTOMERS = 100;
const int MAX_MEMBERS = 100;
const int MAX_STAFF = 100;

int customerCount = 4;
int memberCount = 4;
int staffCount = 10;

Customer customerDB[MAX_CUSTOMERS] = {
    {"C1001", "Viknesh a/l Vijayan", "Male", "013-5678901", "viknesh129@gmail.com", "SolarPower2026!"},
    {"C1002", "Priya a/p Anbalagan", "Female", "014-6789012", "priya59@gmail.com", "Bikoma72!q"},
    {"C1003", "Teo Bao Bin", "Male", "016-7890123", "bb520go@gmail.com", "k8n9vp2m5x"},
    {"C1004", "Lily Yee", "Female", "017-8901234", "lilyisflower43@gmail.com", "K0N9VP2M5Z"}
};

Member memberDB[MAX_MEMBERS] = {
    {"M1001", "Eren Chew", "Male", "017-6543210", "erenono097@gmail.com", "k8N9vP2mX5"},
    {"M1002", "Tan Shin Nang", "Male", "018-2345678", "startan67@gmail.com", "b9M3zP7wR#"},
    {"M1003", "Noor Siti", "Female", "011-12345678", "siti945@gmail.com", "TungtSahur345"},
    {"M1004", "Alice Low", "Female", "019-5678901", "alicelow@gmail.com", "76WhatheDogDoing//"}
};

Staff staffDB[MAX_STAFF] = {
    {"STF1001", "Kim Ji Soo", "Female", "011-2233445", "jisookim123@gmail.com", "k8N9vP2m!", "Hair Stylist"},
    {"STF1002", "Sarah Jenkins", "Female", "017-8899001", "sarah36@gmail.com", "r9W!z2#k&", "Hair Color Stylist"},
    {"STF1003", "Sim Jia Yih", "Female", "011-10546505", "jiayih@gmail.com", "j7N5qW8mX2z%", "Hair Color Stylist"},
    {"STF1004", "Lim Xiao Qing", "Female", "018-9032655", "xiaoqing@gmail.com", "w9K4zM2pR!", "Nail Technician"},
    {"STF1005", "Lim Cai Xuan", "Female", "012-6125939", "caixuan@gmail.com", "t3X8qP5mL9#", "Receptionist"},
    {"STF1006", "Lee Hao Zheng", "Male", "016-5011218", "haozheng@gmail.com", "y8M2!zR9#vW@", "Nail Technician"},
    {"STF1007", "Ng Jun Sheng", "Male", "017-3746889", "junsheng@gmail.com", "h3N9!qX5$k&", "Receptionist"},
    {"STF1008", "Lao Teh", "Male", "017-88990012", "laoteh@gmail.com", "c9P5!xT2$w@", "Skincare Specialist"},
    {"STF1009", "Noor Shahirah", "Female", "010-86043225", "shahirah@gmail.com", "k6P3#wT8$mL&", "Skincare Specialist"},
    {"STF1010", "Roslizawati", "Female", "017-88378451", "rosealwaysrosie@gmail.com", "But860//wt=", "Hair Stylist"}
};

//=======================from haozeng=======================
struct Timeslot {
    int num;
    string time;
    string appointmentID;
    bool isBooked;
    string staffID;
    string staffName;
    string customerID;
    string customerName;
    string service;
    string status;
    double price;
};

int appointmentCounter = 1001;
const int TOTAL_SLOTS = 7;
const int MONTH_IN_YEAR = 12;
const int DAYS_IN_MONTH = 31;
const int daysInMonth[MONTH_IN_YEAR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

Timeslot defaultDaySlots[TOTAL_SLOTS] = {
    {1, "09:00 AM - 11:00 AM", "", false, "", "", "", "", "", "", 0},
    {2, "11:00 AM - 01:00 PM", "", false, "", "", "", "", "", "", 0},
    {3, "01:00 PM - 03:00 PM", "", false, "", "", "", "", "", "", 0},
    {4, "03:00 PM - 05:00 PM", "", false, "", "", "", "", "", "", 0},
    {5, "05:00 PM - 07:00 PM", "", false, "", "", "", "", "", "", 0},
    {6, "07:00 PM - 09:00 PM", "", false, "", "", "", "", "", "", 0},
    {7, "09:00 PM - 11:00 PM", "", false, "", "", "", "", "", "", 0}
};

Timeslot schedule[MONTH_IN_YEAR][DAYS_IN_MONTH][TOTAL_SLOTS];

//=======================from junsheng=======================
struct Services {
    string serviceID;
    string servicename;
    double price;
    int duration;
};

struct Bookings {
    string bookingID;
    string customerID;
    string staffID;
    string serviceID;
    string date;
    string time;
    string status;//confirm, cancelled, completed
    int bill_id;
};

const int MAX_SERVICES = 100; 
const int MAX_BOOKINGS = 100;

int serviceCount = 5;
int bookingCount = 10;

int serviceCounter = 1001;
int bookingCounter = 1001;

Services servicesDB[MAX_SERVICES] = {
    //Service ID, Service Name, Price, Duration
    {"SI1001", "HairCut", 30.00, 30},
    {"SI1002", "HairStyling", 50.00, 60},
    {"SI1003", "Coolouring", 85.00, 90}, 
    {"SI1004", "NailArt", 120.00, 90},
    {"SI1005", "Skin Care Threatment ", 110.00, 90},
};

Bookings bookingDB[MAX_BOOKINGS] = {
    { "B1001", "C1001", "STF1001", "SI1001", "15/08/2026", "09:00 AM", "Completed", 0 },
    { "B1002", "M1001", "STF1002", "SI1002", "16/08/2026", "11:00 AM", "Completed", 0 },
    { "B1003", "C1002", "STF1003", "SI1003", "17/08/2026", "01:00 PM", "Completed", 0 },
    { "B1004", "M1002", "STF1004", "SI1004", "18/08/2026", "03:00 PM", "Completed", 0 },
    { "B1005", "C1003", "STF1005", "SI1005", "19/08/2026", "05:00 PM", "Completed", 0 },
    { "B1006", "M1003", "STF1001", "SI1001", "20/08/2026", "09:00 AM", "Completed", 0 },
    { "B1007", "C1004", "STF1002", "SI1002", "21/08/2026", "11:00 AM", "Completed", 0 },
    { "B1008", "M1004", "STF1003", "SI1003", "22/08/2026", "01:00 PM", "Completed", 0 },
    { "B1009", "C1001", "STF1004", "SI1004", "23/08/2026", "03:00 PM", "Completed", 0 },
    { "B1010", "M1001", "STF1005", "SI1005", "24/08/2026", "05:00 PM", "Completed", 0 },
};
/////// ========================================================================================================== ///////

//=======================from jiayih=======================
int findCustomerIndex(const string& id) {
    for (int i = 0; i < customerCount; i++)
        if (customerDB[i].idCustomer == id) return i;
    return -1;
}

int findMemberIndex(const string& id) {
    for (int i = 0; i < memberCount; i++) {
        if (memberDB[i].idMember == id) {
            return i;
        }
    }
    return -1;
}

int findStaffIndex(const string& id) {
    for (int i = 0; i < staffCount; i++) {
        if (staffDB[i].idStaff == id) {
            return i;
        }
    }
    return -1;
}

//=======================from junsheng=======================
int findServiceID(const string& id) {
    for (int i = 0; i < serviceCount; i++) {
        if (servicesDB[i].serviceID == id) {
            return i;
        }
    }
    return -1;
}

int findBookingID(const string& id) {
    for (int i = 0; i < bookingCount; i++) {
        if (bookingDB[i].bookingID == id) {
            return i;
        }
    }
    return -1;
}

//=======================from haozeng=======================
void inYearlySchedule() {
    for (int month = 0; month < MONTH_IN_YEAR; month++) {
        for (int day = 0; day < DAYS_IN_MONTH; day++) {
            for (int slot = 0; slot < TOTAL_SLOTS; slot++) {
                schedule[month][day][slot] = defaultDaySlots[slot];
            }
        }
    }
}

void LoadScheduleFromFile() {
    ifstream inFile("schedule_data.txt");
    if (!inFile) return;

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        stringstream slotdata(line);
        string item;
        int monthIndex, dayIndex, slotIndex;
        getline(slotdata, item, '|'); monthIndex = stoi(item);
        getline(slotdata, item, '|'); dayIndex = stoi(item);
        getline(slotdata, item, '|'); slotIndex = stoi(item);

        getline(slotdata, item, '|'); schedule[monthIndex][dayIndex][slotIndex].isBooked = (item == "1");
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].appointmentID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].status, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].staffID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].staffName, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].customerID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].customerName, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].service, '|');
        getline(slotdata, item, '|');
        schedule[monthIndex][dayIndex][slotIndex].price = item.empty() ? 0.0 : stod(item);
    }
    inFile.close();
}

void getCurrentSystemTime(int& year, int& month, int& day, int& hour) {
    time_t now = time(0);
    tm localTime;

    localtime_s(&localTime, &now);

    year = 1900 + localTime.tm_year;
    month = 1 + localTime.tm_mon;
    day = localTime.tm_mday;
    hour = localTime.tm_hour;
}
/////// =============================================###END###============================================================ ///////

// ========================================
// ======== Function Declarations =========
// ========================================
int findCustomerIndex(const string& id);
int findMemberIndex(const string& id);
int findStaffIndex(const string& id);
int findServiceID(const string& serviceID);
int findBookingID(const string& id);
void inYearlySchedule();
void LoadScheduleFromFile();
void getCurrentSystemTime(int& year, int& month, int& day, int& hour);
//=======================reporting=======================
bool isValidDateRange(int month, int year, int week);
void loadService();
void loadAppointments();
void loadDataFromTeamSystem();
void logo();
void displayBarchart(string reportTitle, int month, int year, int weekFilter, int type, ostream& out = cout);
void RevenueReport(ostream& out = cout);
void StaffReport(ostream& out = cout);
void ReportExport();
void reportingMenu();
void reporting();
/////// ========================================================================================================== ///////

/////// ####################################### REPORTING ############################################ ///////
struct TotalBooking_Report {
    string appointmentId;
    string customerName;
    string staffName;
    string serviceName;
    int quantity;
    double price;
    int day;
    int month;
    int year;
    string timeSlot;
    string status;
};

const int MAX_REPORT_SIZE = 100;
TotalBooking_Report bookingReport[MAX_SIZE];
int Booking_reportCount = 0;

bool isValidDateRange(int month, int year, int week) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (year < 2000 || year > 2099) {
        return false;
    }
    if (week < 0 || week > 5) {
        return false;
    }
    return true;
}

// use teammate data to load Services
void loadService() {                             //struct Bookings --> struct TotalBooking_Report

    if (bookingCount == 0) {
        cout << "No booking data available for reporting.\n";
        return;
    }

    for (int i = 0; i < bookingCount; i++) {
        const Bookings& booking = bookingDB[i];

        if (booking.status != "Completed") {
            continue;
        }

        int serviceIdx = findServiceID(booking.serviceID); //serviceIdx = i
        // Skip if service is not found
        if (serviceIdx == -1) {
            continue;
        }
        // Stop if report array capacity is reached MAX_REPORT_SIZE
        if (Booking_reportCount >= MAX_REPORT_SIZE) {
            cout << "Report data is full.\n";
            return;
        }

        const Services& service = servicesDB[serviceIdx]; //servicesDB[i]
        bookingReport[Booking_reportCount].appointmentId = booking.bookingID;  //bookingDB[]'s bookingID --> bookingReport[]'s appointmentId

        // Fetch customer name from Customer & Member database
        int custIdx = findCustomerIndex(booking.customerID);
        //if customer is found
        if (custIdx != -1) {
            bookingReport[Booking_reportCount].customerName = customerDB[custIdx].nameCustomer;    //customerDB[]'s nameCustomer --> bookingReport[]'s customerName
        }
        //if customer is not found,try to find member
        else {
            int memIdx = findMemberIndex(booking.customerID);
            //if member is found
            if (memIdx != -1) {
                bookingReport[Booking_reportCount].customerName = memberDB[memIdx].nameMember;      //memberDB[]'s nameMember --> bookingReport[]'s customerName
            }
            else {
                bookingReport[Booking_reportCount].customerName = booking.customerID;               //bookingDB[]'s customerID --> bookingReport[]'s customerName
            }
        }

        // Fetch staff name from Staff database
        int staffIdx = findStaffIndex(booking.staffID);
        if (staffIdx != -1) {
            bookingReport[Booking_reportCount].staffName = staffDB[staffIdx].nameStaff;              //staffDB[]'s nameStaff --> bookingReport[]'s staffName
        }
        else {
            bookingReport[Booking_reportCount].staffName = booking.staffID;                          //bookingDB[]'s staffID --> bookingReport[]'s staffName
        }
        // Set service details, quantity, and price
        bookingReport[Booking_reportCount].serviceName = service.servicename;                        //serviceDB[]'s servicename --> bookingReport[]'s servicename
        bookingReport[Booking_reportCount].quantity = 1;
        bookingReport[Booking_reportCount].price = service.price;                                    //serviceDB[]'s price --> bookingReport[]'s price

        if (booking.date.length() >= 10) {
            ////stoi 08 --> 8
            bookingReport[Booking_reportCount].day = stoi(booking.date.substr(0, 2));                //##exp:31/08/2026 --> substr(0,2) = 31
            bookingReport[Booking_reportCount].month = stoi(booking.date.substr(3, 2));              //##exp:31/08/2026 --> substr(3,2) = 8
            bookingReport[Booking_reportCount].year = stoi(booking.date.substr(6, 4));               //##exp:31/08/2026 --> substr(6,4) = 2026
        }
        else {
            bookingReport[Booking_reportCount].day = 1;
            bookingReport[Booking_reportCount].month = 8;
            bookingReport[Booking_reportCount].year = 2026;
        }

        bookingReport[Booking_reportCount].timeSlot = booking.time;                                  //bookingDB[]'s time --> bookingReport[]'s timeSlot                  
        bookingReport[Booking_reportCount].status = booking.status;                                  //bookingDB[]'s status --> bookingReport[]'s status

        Booking_reportCount++;
    }
}

//use schedule[][] to load Appointments
void loadAppointments() {
    int year, month, currentDay, hour;
    getCurrentSystemTime(year, month, currentDay, hour);

    // ** data created for run only ** //
    for (int monthIndex = 0; monthIndex < MONTH_IN_YEAR; monthIndex++) {
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                Timeslot& slot = schedule[monthIndex][dayIndex][slotIndex];


                //only load booked or completed timeslots
                if (!slot.isBooked) {
                    continue;
                }

                if (Booking_reportCount >= MAX_SIZE) {
                    cout << "Report data is full.\n";
                    return;
                }

                TotalBooking_Report& report = bookingReport[Booking_reportCount];

                report.appointmentId = slot.appointmentID;
                report.customerName = slot.customerName;
                report.staffName = slot.staffName;
                report.serviceName = slot.service;
                report.price = slot.price;
                report.quantity = 1;
                report.day = dayIndex + 1;
                report.month = monthIndex + 1;
                report.year = year;
                report.timeSlot = slot.time;
                report.status = slot.status;

                Booking_reportCount++;
            }
        }
    }
}

void loadDataFromTeamSystem() {
    Booking_reportCount = 0;

    loadService();
    loadAppointments();
}

// ** Display Logo ** //
void logo() {
    cout << R"(
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
 ######    ######       ######     ###    ##        #######  ##    ##    
##    ##  ##    ##     ##    ##   ## ##   ##       ##     ## ###   ##    
##        ##           ##        ##   ##  ##       ##     ## ####  ##    
##   #### ##   ####     ######  ##     ## ##       ##     ## ## ## ##    
##    ##  ##    ##           ## ######### ##       ##     ## ##  ####    
##    ##  ##    ##     ##    ## ##     ## ##       ##     ## ##   ###    
 ######    ######       ######  ##     ## ########  #######  ##    ##    
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
)" << endl;
}

// ** Display Barchart(revenue&staff) ** //
void displayBarchart(string reportTitle, int month, int year, int weekFilter, int type, ostream& out) {
    out << "\n=== " << reportTitle << " (BARCHART) ===" << endl;
    out << "------------------------------------" << endl;

    string names[MAX_SIZE];
    double values[MAX_SIZE] = { 0 };
    int count = 0;

    for (int i = 0; i < Booking_reportCount; i++) {
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (weekFilter == 0) || (currentWeek == weekFilter);

        if ((bookingReport[i].status == "Completed") &&
            bookingReport[i].month == month &&
            bookingReport[i].year == year && weekMatch)
        {
            string key = (type == 1) ? bookingReport[i].serviceName : bookingReport[i].staffName;
            double val = (type == 1) ? (bookingReport[i].quantity * bookingReport[i].price) : bookingReport[i].quantity;

            bool found = false;
            for (int j = 0; j < count; j++) {
                if (names[j] == key) {
                    values[j] += val;
                    found = true;
                    break;
                }
            }
            if (!found) {
                names[count] = key;
                values[count] = val;
                count++;
            }
        }
    }

    if (count == 0) {
        out << "No records found for this timeframe." << endl;
    }
    else {
        for (int i = 0; i < count; i++) {
            out << left << setw(28) << names[i] << " | ";

            int stars = (type == 1) ? (int)(values[i] / 50) : (int)values[i];            
            for (int k = 0; k < stars; k++) 
                out << "*";

            if (type == 1) {
                out << "   (RM " << fixed << setprecision(2) << values[i] << ")" << endl;
            }
            else {
                out << "   (" << (int)values[i] << " times)" << endl;
            }
        }
    }
    out << "------------------------------------" << endl;
}

// ** Revenue Report ** //
void RevenueReport(ostream& out) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter MM/YYYY/W (week0 is for Monthly): ";
    
    if (!(cin >> targetMonth >> targetYear >> targetWeek) ||
        !isValidDateRange(targetMonth, targetYear, targetWeek)) {

        // Clear all characters until newline
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nInvalid date range!" << endl;
        return;
    }

    loadDataFromTeamSystem(); 

    string serviceNames[MAX_SIZE];
    int serviceQty[MAX_SIZE] = { 0 };           
    double serviceUnitPrice[MAX_SIZE] = { 0.0 }; 
    double serviceRevenue[MAX_SIZE] = { 0.0 };    
    int serviceTypeCount = 0;
    double totalRevenue = 0.0;

    for (int i = 0; i < Booking_reportCount; i++) {
        // Calculate current week number (Week 1 to 5)
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if ((bookingReport[i].status == "Completed") &&
            bookingReport[i].month == targetMonth &&
            bookingReport[i].year == targetYear &&
            weekMatch) {

            // Check if service already exists in the list
            double amount = bookingReport[i].quantity * bookingReport[i].price;  
            bool found = false;
            for (int j = 0; j < serviceTypeCount; j++) {
                if (serviceNames[j] == bookingReport[i].serviceName) {
                    serviceQty[j] += bookingReport[i].quantity;
                    serviceRevenue[j] += amount;
                    found = true;
                    break;
                }
            }
            // Add new service entry if not found in the list
            if (!found) {
                serviceNames[serviceTypeCount] = bookingReport[i].serviceName;
                serviceQty[serviceTypeCount] = bookingReport[i].quantity;
                serviceUnitPrice[serviceTypeCount] = bookingReport[i].price;
                serviceRevenue[serviceTypeCount] = amount;
                serviceTypeCount++;
            }
        }
    }

    out << "\n============================================================================" << endl;
    if (targetWeek > 0)
        out << "                    REVENUE REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
    else
        out << "                    MONTHLY REVENUE REPORT FOR " << targetMonth << "/" << targetYear << endl;
    out << "============================================================================" << endl;
    out << left << setw(28) << "Service Name" 
        << right << setw(10) << "Unit Price"  
        << setw(12) << "Total Qty"
        << setw(17) << "Total Amount" << endl;
    out << "----------------------------------------------------------------------------" << endl;
     
    for (int i = 0; i < serviceTypeCount; i++) {
        totalRevenue += serviceRevenue[i]; 

        out << left << setw(28) << serviceNames[i]
            << right << setw(4) << "RM " << setw(7) << fixed << setprecision(2) << serviceUnitPrice[i]
            << setw(9) << serviceQty[i]
            << setw(11) << "RM " << setw(9) << serviceRevenue[i] << endl;
    }

    out << "----------------------------------------------------------------------------" << endl;
    out << "TOTAL REVENUE GENERATED: RM " << fixed << setprecision(2) << totalRevenue << endl;
    out << "============================================================================" << endl;

	// use bubble sort to find the top service
    if (serviceTypeCount > 0) {
        int topIdx = 0;
        for (int i = 1; i < serviceTypeCount; i++) {
            if (serviceRevenue[i] > serviceRevenue[topIdx]) {
                topIdx = i;
            }
        }
        out << "\n*** TOP SERVICE ***" << endl;
        out << " Highest Revenue Service: " << serviceNames[topIdx]
            << " (Total: RM " << fixed << setprecision(2) << serviceRevenue[topIdx]
            << ", Total Qty: " << serviceQty[topIdx] << ")" << endl;
    }

    string title = (targetWeek > 0) ? "WEEKLY REVENUE" : "MONTHLY REVENUE";
    displayBarchart(title, targetMonth, targetYear, targetWeek, 1, out);
}

// ** Staff Report ** //
void StaffReport(ostream& out) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter MM/YYYY/W (week0 is for Monthly): ";
    
    if (!(cin >> targetMonth >> targetYear >> targetWeek) ||
        !isValidDateRange(targetMonth, targetYear, targetWeek)) {

        // Clear all characters until newline
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nInvalid date range!" << endl;
        return; 
    }

    loadDataFromTeamSystem();

    string staffNames[MAX_SIZE];
    int serviceCounts[MAX_SIZE] = { 0 };
    int uniqueStaff = 0;
    int totalServicesHandled = 0;

    for (int i = 0; i < Booking_reportCount; i++) {
        // Calculate current week number (Week 1 to 5)
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if (( bookingReport[i].status == "Completed") &&  
            bookingReport[i].month == targetMonth &&
            bookingReport[i].year == targetYear && weekMatch)
        {
            bool found = false;
            // Check if service already exists in the list
            for (int j = 0; j < uniqueStaff; j++) {
                if (staffNames[j] == bookingReport[i].staffName) {
                    serviceCounts[j] += bookingReport[i].quantity;
                    found = true;
                    break;
                }
            }
            // Add new staff entry if not found in the list
            if (!found) {
                staffNames[uniqueStaff] = bookingReport[i].staffName;
                serviceCounts[uniqueStaff] = bookingReport[i].quantity;
                uniqueStaff++;
            }
        }
    }

    out << "\n============================================================================" << endl;
    if (targetWeek > 0)
        out << "                 STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
    else
        out << "                 MONTHLY STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear << endl;
    out << "============================================================================" << endl;

    out << left << setw(40) << "Staff Name"
        << right << setw(20) << "Services Handled" << endl;
    out << "----------------------------------------------------------------------------" << endl;

	// print each staff's service count
    for (int j = 0; j < uniqueStaff; j++) {
        totalServicesHandled += serviceCounts[j];
        out << left << setw(40) << staffNames[j]
            << right << setw(20) << serviceCounts[j] << endl;
    }

    out << "----------------------------------------------------------------------------" << endl;
    out << left << setw(40) << "TOTAL SERVICES COMPLETED:"
        << right << setw(20) << totalServicesHandled << endl;
    out << "============================================================================" << endl;

    string title = (targetWeek > 0) ? "WEEKLY STAFF WORKLOAD" : "MONTHLY STAFF WORKLOAD";
    displayBarchart(title, targetMonth, targetYear, targetWeek, 2, out);
}

// ** Report Export ** //
void ReportExport() {
    int exportChoice;
    cout << "\n=== REPORT EXPORT ===" << endl;
    cout << "1. Export Revenue Report" << endl;
    cout << "2. Export Staff Report" << endl;
    cout << "Please select report type to export: ";
    cin >> exportChoice;

    if (exportChoice != 1 && exportChoice != 2) {
        cout << "Invalid choice." << endl;
        return;
    }
    
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter MM/YYYY/W (week0 is for Monthly): ";

    if (!(cin >> targetMonth >> targetYear >> targetWeek) ||
        !isValidDateRange(targetMonth, targetYear, targetWeek)) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nInvalid date range!" << endl;
        cout << "\n--> Report export failed!" << endl;           // if invalid,stop the process
        return;
    }

    ofstream outFile("report_export.txt");
    if (!outFile.is_open()) {
        cout << "--> File output error!" << endl;
        return;
    }

    if (exportChoice == 1) {
        RevenueReport(outFile);
    }
    else {
        StaffReport(outFile);
    }

    outFile.close();
    cout << "\n--> Report printed successfully!" << endl;
}

// Display Menu
void reportingMenu() {
    cout << "\n========================================" << endl;
    cout << "        REPORTING SYSTEM                " << endl;
    cout << "========================================" << endl;
    cout << "1. Revenue Report (Weekly / Monthly)" << endl;
    cout << "2. Staff Report (Weekly / Monthly)" << endl;
    cout << "3. Report Export" << endl;
    cout << "0. Exit" << endl;
    cout << "Please choose an option: ";
}

void reporting() {
    int option;
    do {
        reportingMenu();
        cin >> option;

        switch (option) {

        case 1:
            RevenueReport();
            break;
        case 2:
            StaffReport();
            break;
        case 3:
            ReportExport();
            break;
        case 0:
            cout << "\nExiting program." << endl;
            break;
        default:
            cout << "\nInvalid option. Please try again." << endl;
            break;
        }

        if (option >= 1 && option <= 4) {
            cout << "\nPress Enter to return to menu...";
            cin.ignore();
            cin.get();
        }

    } while (option != 0);
}

// MAIN
int main() {
    logo();
    inYearlySchedule();
    LoadScheduleFromFile();
    loadDataFromTeamSystem();

    reporting();

    return 0;
}