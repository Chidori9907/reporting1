#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <unordered_map>
#include <limits>
#include <cctype>
using namespace std;

const int MAX_SIZE = 100;
//teammates data
struct Customer {
    string nameCustomer;
    string genderCustomer;
    string phoneCustomer;
    string emailCustomer;
    string passwordCustomer;
};

struct Member {
    string nameMember;
    string genderMember;
    string phoneMember;
    string emailMember;
    string passwordMember;
};

struct Staff {
    string nameStaff;
    string genderStaff;
    string phoneStaff;
    string emailStaff;
    string passwordStaff;
    string positionStaff;
};

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
    string status; // confirm, cancelled, completed
};

// from jiayih
unordered_map<string, Customer> customerDB = {
    {"C1001", {"Viknesh a/l Vijayan", "Male", "013-5678901", "viknesh129@gmail.com", "SolarPower2026!"}},
    {"C1002", {"Priya a/p Anbalagan", "Female", "014-6789012", "priya59@gmail.com", "Bikoma72!q"}},
    {"C1003", {"Teo Bao Bin", "Male", "016-7890123", "bb520go@gmail.com", "k8n9vp2m5x"}},
    {"C1004", {"Lily Yee", "Female", "017-8901234", "lilyisflower43@gmail.com", "K0N9VP2M5Z"}},
};

unordered_map<string, Member> memberDB = {
    {"M1001", {"Eren Chew", "Male", "017-6543210", "erenono097@gmail.com", "k8N9vP2mX5"}},
    {"M1002", {"Tan Shin Nang", "Male", "018-2345678", "startan67@gmail.com", "b9M3zP7wR#"}},
    {"M1003", {"Noor Siti", "Female", "011-12345678", "siti945@gmail.com", "TungtSahur345"}},
    {"M1004", {"Alice Low", "Female", "019-5678901", "alicelow@gmail.com", "76WhatheDogDoing//"}}
};

unordered_map<string, Staff> staffDB = {
    {"STF1001", {"Kim Ji Soo", "Female", "011-2233445", "jisookim123@gmail.com", "k8N9vP2m!", "Hair Stylist"}},
    {"STF1002", {"Sarah Jenkins", "Female", "017-8899001", "sarah36@gmail.com", "r9W!z2#k&", "Hair Color Stylist"}},
    {"STF1003", {"Sim Jia Yih", "Female", "011-10546505", "jiayih@gmail.com", "j7N5qW8mX2z%", "Hair Color Stylist"}},
    {"STF1004", {"Lim Xiao Qing", "Female", "018-9032655", "xiaoqing@gmail.com", "w9K4zM2pR!", "Nail Technician"}},
    {"STF1005", {"Lim Cai Xuan", "Female", "012-6125939", "caixuan@gmail.com", "t3X8qP5mL9#", "Receptionist"}},
    {"STF1006", {"Lee Hao Zheng", "Male", "016-5011218", "haozheng@gmail.com", "y8M2!zR9#vW@", "Nail Technician"}},
    {"STF1007", {"Ng Jun Sheng", "Male", "017-3746889", "junsheng@gmail.com", "h3N9!qX5$k&", "Receptionist"}},
    {"STF1008", {"Lao Teh", "Male", "017-88990012", "laoteh@gmail.com", "c9P5!xT2$w@", "Skincare Specialist"}},
    {"STF1009", {"Noor Shahirah", "Female", "010-86043225", "shahirah@gmail.com", "k6P3#wT8$mL&", "Skincare Specialist"}},
    {"STF1010", {"Roslizawati", "Female", "017-88378451", "rosealwaysrosie@gmail.com", "But860//wt=", "Hair Stylist"}},
};
// from junsheng
unordered_map<string, Services> servicesDB = {
    {"SI1001", {"SI1001", "HairCut", 30.00, 30}},
    {"SI1002", {"SI1002", "HairStyling", 50.00, 60}},
    {"SI1003", {"SI1003", "Colouring", 85.00, 90}},
    {"SI1004", {"SI1004", "NailArt", 120.00, 90}},
    {"SI1005", {"SI1005", "Skin Care Treatment", 110.00, 90}},
};

unordered_map<string, Bookings> bookingDB;
int bookingCounter = 1011;

// Revenue report need Appointment data
struct Appointment {
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

Appointment appointments[MAX_SIZE];
int appointmentCount = 0;

bool validateBooking(const Bookings& booking) {
    if (booking.customerID.empty()) return false;
    if (servicesDB.find(booking.serviceID) == servicesDB.end()) return false;
    if (staffDB.find(booking.staffID) == staffDB.end()) return false;
    if (booking.date.empty()) return false;
    if (booking.time.empty()) return false;
    if (booking.status.empty()) return false;
    return true;
}

void viewServices() {
    cout << "\n========================================\n";
    cout << right << setw(10) << "SERVICES\n";
    cout << "========================================\n";
    for (const auto& entry : servicesDB) {
        const Services& services = entry.second;
        cout << "Service ID : " << services.serviceID << "\n";
        cout << "Service    : " << services.servicename << "\n";
        cout << "Price      : RM " << fixed << setprecision(2) << services.price << "\n";
        cout << "Duration   : " << services.duration << " minutes\n";
        cout << "----------------------------------------\n";
    }
}

void addSingleBooking(const string& customerID) {
    Bookings sinBooking;
    sinBooking.bookingID = "B" + to_string(bookingCounter++);
    sinBooking.customerID = customerID;
    sinBooking.status = "Confirmed";

    cout << "\n========== ADD SINGLE BOOKING ==========\n";
    viewServices();

    cout << "Enter Service ID: ";
    cin >> sinBooking.serviceID;
    if (servicesDB.find(sinBooking.serviceID) == servicesDB.end()) {
        cout << "[Error] Service ID not found.\n";
        return;
    }

    cout << "Enter Staff ID: ";
    cin >> sinBooking.staffID;
    if (staffDB.find(sinBooking.staffID) == staffDB.end()) {
        cout << "[Error] Staff ID not found.\n";
        return;
    }

    cout << "Enter Date (DD/MM/YYYY): ";
    cin >> sinBooking.date;
    cout << "Enter Time (HH:MM): ";
    cin >> sinBooking.time;

    if (!validateBooking(sinBooking)) {
        cout << "[Error] Booking validation failed.\n";
        return;
    }

    bookingDB[sinBooking.bookingID] = sinBooking;
    cout << "\n[Success] Booking added successfully!\n";
    cout << "Booking ID: " << sinBooking.bookingID << "\n";
}

void viewBooking(const string& customerID) {
    bool found = false;
    cout << "\n========== MY BOOKINGS ==========\n";
    for (const auto& entry : bookingDB) {
        const Bookings& viewbooking = entry.second;
        if (viewbooking.customerID == customerID) {
            found = true;
            cout << "\nBooking ID : " << viewbooking.bookingID << "\n";
            cout << "Service ID : " << viewbooking.serviceID << "\n";
            cout << "Staff ID   : " << viewbooking.staffID << "\n";
            cout << "Date       : " << viewbooking.date << "\n";
            cout << "Time       : " << viewbooking.time << "\n";
            cout << "Status     : " << viewbooking.status << "\n";
            cout << "--------------------------------\n";
        }
    }
    if (!found) {
        cout << "No bookings found.\n";
    }
}

void cancelBooking(const string& customerID) {
    string cancelid;
    cout << "\nEnter Booking ID to cancel: ";
    cin >> cancelid;

    auto itcancel = bookingDB.find(cancelid);
    if (itcancel == bookingDB.end()) {
        cout << "[Error] Booking not found.\n";
        return;
    }
    if (itcancel->second.customerID != customerID) {
        cout << "[Error] You cannot cancel this booking.\n";
        return;
    }
    if (itcancel->second.status == "Cancelled") {
        cout << "[Error] Booking is already cancelled.\n";
        return;
    }
    itcancel->second.status = "Cancelled";
    cout << "\n[Success] Booking " << cancelid << " has been cancelled.\n";
}
// use teammate data to load Appointment
void loadDataFromTeamSystem() {
    appointmentCount = 0;
    int counter = 1;

    // from bookingDB to get appoinement data
    if (!bookingDB.empty()) {
        for (const auto& entry : bookingDB) {
            const Bookings& booking = entry.second;

            // use completed / confirmed appoinment data
            if (booking.status == "Completed" || booking.status == "Confirmed") {
                auto itService = servicesDB.find(booking.serviceID);
                if (itService != servicesDB.end()) {
                    const Services& service = itService->second;

                    appointments[appointmentCount].appointmentId = booking.bookingID;

                    // from customerDB / memberDB get customer name
                    auto itCust = customerDB.find(booking.customerID);
                    if (itCust != customerDB.end()) {
                        appointments[appointmentCount].customerName = itCust->second.nameCustomer;
                    }
                    else {
                        auto itMem = memberDB.find(booking.customerID);
                        if (itMem != memberDB.end()) {
                            appointments[appointmentCount].customerName = itMem->second.nameMember;
                        }
                        else {
                            appointments[appointmentCount].customerName = booking.customerID;
                        }
                    }

                    // from staffDB to get staff name
                    auto itStaff = staffDB.find(booking.staffID);
                    if (itStaff != staffDB.end()) {
                        appointments[appointmentCount].staffName = itStaff->second.nameStaff;
                    }
                    else {
                        appointments[appointmentCount].staffName = booking.staffID;
                    }

                    appointments[appointmentCount].serviceName = service.servicename;
                    appointments[appointmentCount].quantity = 1;
                    appointments[appointmentCount].price = service.price;

                    // appointment date (DD/MM/YYYY)
                    if (booking.date.length() >= 10) {
                        appointments[appointmentCount].day = stoi(booking.date.substr(0, 2));
                        appointments[appointmentCount].month = stoi(booking.date.substr(3, 2));
                        appointments[appointmentCount].year = stoi(booking.date.substr(6, 4));
                    }
                    else {
                        appointments[appointmentCount].day = 1;
                        appointments[appointmentCount].month = 8;
                        appointments[appointmentCount].year = 2026;
                    }

                    appointments[appointmentCount].timeSlot = booking.time;
                    appointments[appointmentCount].status = booking.status;

                    appointmentCount++;
                    counter++;
                }
            }
        }
    }
    // if bookingDB empty,use servicesDB + staffDB to create data
    else {
        for (const auto& entry : servicesDB) {
            const Services& service = entry.second;

            appointments[appointmentCount].appointmentId = "B" + to_string(1000 + counter);

            // customer
            int custIdx = (counter - 1) % customerDB.size();
            auto custIt = customerDB.begin();
            advance(custIt, custIdx);
            appointments[appointmentCount].customerName = custIt->second.nameCustomer;

            // staff
            int staffIdx = (counter - 1) % staffDB.size();
            auto staffIt = staffDB.begin();
            advance(staffIt, staffIdx);
            appointments[appointmentCount].staffName = staffIt->second.nameStaff;

            appointments[appointmentCount].serviceName = service.servicename;
            appointments[appointmentCount].quantity = 1;
            appointments[appointmentCount].price = service.price;
            appointments[appointmentCount].day = 10 + (counter % 20);
            appointments[appointmentCount].month = 8;
            appointments[appointmentCount].year = 2026;
            appointments[appointmentCount].timeSlot = (counter % 2 == 0) ? "10:00 AM - 11:00 AM" : "02:00 PM - 03:00 PM";
            appointments[appointmentCount].status = "Completed";

            appointmentCount++;
            counter++;
        }
    }
}

// Display Logo
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

// Display Barchart(revenue&staff)
void displayBarchart(string reportTitle, int month, int year, int weekFilter = 0, ostream& out = cout) {
    out << "\n=== " << reportTitle << " (BARCHART) ===" << endl;
    out << "------------------------------------" << endl;
    string services[MAX_SIZE];
    double totals[MAX_SIZE] = { 0 };
    int count = 0;

    for (int i = 0; i < appointmentCount; i++) {
        int currentWeek = (appointments[i].day - 1) / 7 + 1;
        bool weekMatch = (weekFilter == 0) || (currentWeek == weekFilter);

        if (appointments[i].status == "Completed" &&
            appointments[i].month == month &&
            appointments[i].year == year &&
            weekMatch)
        {
            bool found = false;
            for (int j = 0; j < count; j++) {
                if (services[j] == appointments[i].serviceName) {
                    totals[j] += (appointments[i].quantity * appointments[i].price);
                    found = true;
                    break;
                }
            }
            if (!found) {
                services[count] = appointments[i].serviceName;
                totals[count] = appointments[i].quantity * appointments[i].price;
                count++;
            }
        }
    }

    if (count == 0) {
        out << "No completed records found for this timeframe." << endl;
    }
    else {
        for (int i = 0; i < count; i++) {
            out << left << setw(12) << services[i] << " | ";
            int stars = (int)(totals[i] / 50);
            for (int k = 0; k < stars; k++) out << "*";
            out << " (RM " << fixed << setprecision(2) << totals[i] << ")" << endl;
        }
    }
    out << "------------------------------------" << endl;
}

// Revenue Report need services data
void RevenueReport(ostream& out = cout) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter Month/Year/Week (week0 is for Monthly): ";
    cin >> targetMonth >> targetYear >> targetWeek;

    loadDataFromTeamSystem();

    double totalRevenue = 0;
    string serviceNames[MAX_SIZE];
    int serviceQty[MAX_SIZE] = { 0 };
    double serviceRevenue[MAX_SIZE] = { 0.0 };
    int serviceTypeCount = 0;

    out << "\n========================================================" << endl;
    if (targetWeek > 0)
        out << "      REVENUE REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
    else
        out << "      MONTHLY REVENUE REPORT FOR " << targetMonth << "/" << targetYear << endl;
    out << "========================================================" << endl;
    out << left << setw(10) << "ID"
        << setw(15) << "Service"
        << setw(8) << "Qty"
        << setw(10) << "Price"
        << "Total Amount" << endl;
    out << "--------------------------------------------------------" << endl;

    for (int i = 0; i < appointmentCount; i++) {
        int currentWeek = (appointments[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if (appointments[i].status == "Completed" &&
            appointments[i].month == targetMonth &&
            appointments[i].year == targetYear &&
            weekMatch) {

            double amount = appointments[i].quantity * appointments[i].price;
            totalRevenue += amount;

            out << left << setw(10) << appointments[i].appointmentId
                << setw(15) << appointments[i].serviceName
                << setw(8) << appointments[i].quantity
                << "RM" << setw(8) << fixed << setprecision(2) << appointments[i].price
                << "RM " << amount << endl;

            bool found = false;
            for (int j = 0; j < serviceTypeCount; j++) {
                if (serviceNames[j] == appointments[i].serviceName) {
                    serviceQty[j] += appointments[i].quantity;
                    serviceRevenue[j] += amount;
                    found = true;
                    break;
                }
            }
            if (!found) {
                serviceNames[serviceTypeCount] = appointments[i].serviceName;
                serviceQty[serviceTypeCount] = appointments[i].quantity;
                serviceRevenue[serviceTypeCount] = amount;
                serviceTypeCount++;
            }
        }
    }

    out << "--------------------------------------------------------" << endl;
    out << "TOTAL REVENUE GENERATED: RM " << fixed << setprecision(2) << totalRevenue << endl;
    out << "========================================================" << endl;

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
    displayBarchart(title, targetMonth, targetYear, targetWeek, out);
}

// Staff Report need staff data
void StaffReport(ostream& out = cout) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter Month Year Week (week0 is for Monthly): ";
    cin >> targetMonth >> targetYear >> targetWeek;

    loadDataFromTeamSystem();

    string staffNames[MAX_SIZE];
    int serviceCounts[MAX_SIZE] = { 0 };
    int uniqueStaff = 0;

    for (int i = 0; i < appointmentCount; i++) {
        int currentWeek = (appointments[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if (appointments[i].status == "Completed" &&
            appointments[i].month == targetMonth &&
            appointments[i].year == targetYear && weekMatch)
        {
            bool found = false;
            for (int j = 0; j < uniqueStaff; j++) {
                if (staffNames[j] == appointments[i].staffName) {
                    serviceCounts[j] += appointments[i].quantity;
                    found = true;
                    break;
                }
            }
            if (!found) {
                staffNames[uniqueStaff] = appointments[i].staffName;
                serviceCounts[uniqueStaff] = appointments[i].quantity;
                uniqueStaff++;
            }
        }
    }

    out << "\n=== STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear;
    if (targetWeek > 0) out << " (WEEK " << targetWeek << ")";
    out << " ===" << endl;
    out << "------------------------------------" << endl;
    out << left << setw(15) << "Staff Name" << "Services Handled" << endl;
    out << "------------------------------------" << endl;

    if (uniqueStaff == 0) {
        out << "No staff workload found for this timeframe." << endl;
    }
    else {
        for (int i = 0; i < uniqueStaff; i++) {
            out << left << setw(15) << staffNames[i] << serviceCounts[i] << endl;
        }
    }
    out << "------------------------------------" << endl;

    out << "\n=== STAFF WORKLOAD (BARCHART) ===" << endl;
    for (int i = 0; i < uniqueStaff; i++) {
        out << left << setw(10) << staffNames[i] << " | ";
        for (int k = 0; k < serviceCounts[i]; k++) out << "*";
        out << " (" << serviceCounts[i] << " services)" << endl;
    }
    out << "------------------------------------" << endl;
}

// Report Export
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
void menu() {
    cout << "\n========================================" << endl;
    cout << "        REPORTING SYSTEM                " << endl;
    cout << "========================================" << endl;
    cout << "1. Revenue Report (Weekly / Monthly)" << endl;
    cout << "2. Staff Report (Weekly / Monthly)" << endl;
    cout << "3. Report Export" << endl;
    cout << "0. Exit" << endl;
    cout << "Please choose an option: ";
}

// MAIN
int main() {
    logo();
    //created 12 months of test booking data
    string months[] = { "01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12" };
    string serviceIDs[] = { "SI1001", "SI1002", "SI1003", "SI1004", "SI1005" };
    string staffIDs[] = { "STF1001", "STF1002", "STF1003", "STF1004", "STF1005" };
    string customerIDs[] = { "C1001", "C1002", "C1003", "C1004", "M1001", "M1002" };

    for (int i = 0; i < 12; i++) {
        Bookings b;
        b.bookingID = "B" + to_string(1001 + i);
        b.customerID = customerIDs[i % 6];
        b.staffID = staffIDs[i % 5];
        b.serviceID = serviceIDs[i % 5];
        b.date = "15/" + months[i] + "/2026";
        b.time = "10:00";
        b.status = "Completed";
        bookingDB[b.bookingID] = b;
    }

    loadDataFromTeamSystem();

    cout << "\n[System] Team data loaded successfully!" << endl;
    cout << "[System] Services: " << servicesDB.size()
        << " | Staff: " << staffDB.size()
        << " | Appointments: " << appointmentCount << endl;

    int option;
    do {
        menu();
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
            cout << "\nExiting program. Goodbye!" << endl;
            break;
        default:
            cout << "\nInvalid option. Please try again." << endl;
            break;
        }

        if (option >= 1 && option <= 3) {
            cout << "\nPress Enter to return to menu...";
            cin.ignore();
            cin.get();
        }

    } while (option != 0);

    return 0;
}