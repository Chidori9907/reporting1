//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iomanip>
//#include <limits>
//#include <cctype>
//#include <ctime>
//using namespace std;
//
//const int MAX_SIZE = 100;
////from jiayih
//struct Customer {
//    string idCustomer;
//    string nameCustomer;
//    string genderCustomer;
//    string phoneCustomer;
//    string emailCustomer;
//    string passwordCustomer;
//};
//
//struct Member {
//    string idMember;
//    string nameMember;
//    string genderMember;
//    string phoneMember;
//    string emailMember;
//    string passwordMember;
//};
//
//struct Staff {
//    string idStaff;
//    string nameStaff;
//    string genderStaff;
//    string phoneStaff;
//    string emailStaff;
//    string passwordStaff;
//    string positionStaff;
//};
//
//struct Timeslot {
//    int id;
//    string time;
//    bool isBooked;
//    string staffID;
//    string staffName;
//    string customerID;
//    string customerName;
//    string service;
//    string status;
//};
//
//struct Services {
//    string serviceID;
//    string servicename;
//    double price;
//    int duration;
//};
//
//struct Bookings {
//    string bookingID;
//    string customerID;
//    string staffID;
//    string serviceID;
//    string date;
//    string time;
//    string status; 
//};
//
//int customerCounter = 1005;
//int memberCounter = 1005;
//int staffCounter = 1011;
//
//const int MAX_CUSTOMERS = 100;
//const int MAX_MEMBERS = 100;
//const int MAX_STAFF = 100;
//
//int customerCount = 4;
//int memberCount = 4;
//int staffCount = 10;
//
//const int TOTAL_SLOTS = 7;
//const int DAYS_IN_MONTH = 31;
//
//Timeslot defaultDaySlots[TOTAL_SLOTS] = {
//    {1, "09:00 AM - 11:00 AM", false, "", "", "", "", "", ""},
//    {2, "11:00 AM - 01:00 PM", false, "", "", "", "", "", ""},
//    {3, "01:00 PM - 03:00 PM", false, "", "", "", "", "", ""},
//    {4, "03:00 PM - 05:00 PM", false, "", "", "", "", "", ""},
//    {5, "05:00 PM - 07:00 PM", false, "", "", "", "", "", ""},
//    {6, "07:00 PM - 09:00 PM", false, "", "", "", "", "", ""},
//    {7, "09:00 PM - 11:00 PM", false, "", "", "", "", "", ""}
//};
//
//Timeslot schedule[DAYS_IN_MONTH][TOTAL_SLOTS];
//
//const string RESET = "\033[0m";
//const string RED = "\033[31m";
//const string GREEN = "\033[32m";
//const string YELLOW = "\033[93m";
//
//
//Customer customerDB[MAX_CUSTOMERS] = {
//    {"C1001", "Viknesh a/l Vijayan", "Male", "013-5678901", "viknesh129@gmail.com", "SolarPower2026!"},
//    {"C1002", "Priya a/p Anbalagan", "Female", "014-6789012", "priya59@gmail.com", "Bikoma72!q"},
//    {"C1003", "Teo Bao Bin", "Male", "016-7890123", "bb520go@gmail.com", "k8n9vp2m5x"},
//    {"C1004", "Lily Yee", "Female", "017-8901234", "lilyisflower43@gmail.com", "K0N9VP2M5Z"}
//};
//
//Member memberDB[MAX_MEMBERS] = {
//    {"M1001", "Eren Chew", "Male", "017-6543210", "erenono097@gmail.com", "k8N9vP2mX5"},
//    {"M1002", "Tan Shin Nang", "Male", "018-2345678", "startan67@gmail.com", "b9M3zP7wR#"},
//    {"M1003", "Noor Siti", "Female", "011-12345678", "siti945@gmail.com", "TungtSahur345"},
//    {"M1004", "Alice Low", "Female", "019-5678901", "alicelow@gmail.com", "76WhatheDogDoing//"}
//};
//
//Staff staffDB[MAX_STAFF] = {
//    {"STF1001", "Kim Ji Soo", "Female", "011-2233445", "jisookim123@gmail.com", "k8N9vP2m!", "Hair Stylist"},
//    {"STF1002", "Sarah Jenkins", "Female", "017-8899001", "sarah36@gmail.com", "r9W!z2#k&", "Hair Color Stylist"},
//    {"STF1003", "Sim Jia Yih", "Female", "011-10546505", "jiayih@gmail.com", "j7N5qW8mX2z%", "Hair Color Stylist"},
//    {"STF1004", "Lim Xiao Qing", "Female", "018-9032655", "xiaoqing@gmail.com", "w9K4zM2pR!", "Nail Technician"},
//    {"STF1005", "Lim Cai Xuan", "Female", "012-6125939", "caixuan@gmail.com", "t3X8qP5mL9#", "Receptionist"},
//    {"STF1006", "Lee Hao Zheng", "Male", "016-5011218", "haozheng@gmail.com", "y8M2!zR9#vW@", "Nail Technician"},
//    {"STF1007", "Ng Jun Sheng", "Male", "017-3746889", "junsheng@gmail.com", "h3N9!qX5$k&", "Receptionist"},
//    {"STF1008", "Lao Teh", "Male", "017-88990012", "laoteh@gmail.com", "c9P5!xT2$w@", "Skincare Specialist"},
//    {"STF1009", "Noor Shahirah", "Female", "010-86043225", "shahirah@gmail.com", "k6P3#wT8$mL&", "Skincare Specialist"},
//    {"STF1010", "Roslizawati", "Female", "017-88378451", "rosealwaysrosie@gmail.com", "But860//wt=", "Hair Stylist"}
//};
//// from junsheng(change
//const int MAX_SERVICES = 100;
//const int MAX_BOOKINGS = 100;
//
//Services servicesDB[MAX_SERVICES] = {
//    //Service ID, Service Name, Price, Duration
//    {"SI1001", "HairCut", 30.00, 30},
//    {"SI1002", "HairStyling", 50.00, 60},
//    {"SI1003", "Coolouring", 85.00, 90},
//    {"SI1004", "NailArt", 120.00, 90},
//    {"SI1005", "Skin Care Threatment ", 110.00, 90},
//};
//
//Bookings bookingDB[MAX_BOOKINGS];
//
//int serviceCount = 5;
//int bookingCount = 0;
//
//int serviceCounter = 1001;
//int bookingCounter = 1001;
//
////reporting module
//struct Appointment {
//    string appointmentId;
//    string customerName;
//    string staffName;
//    string serviceName;
//    int quantity;
//    double price;
//    int day;
//    int month;
//    int year;
//    string timeSlot;
//    string status;
//};
//
//Appointment appointments[MAX_SIZE];
//int appointmentCount = 0;
//
//// ========================================
//// REPORTING MODULE - Function Declarations
//// ========================================
//void loadDataFromTeamSystem();
//void getCurrentSystemTime(int& year, int& month, int& day, int& hour);
//void SearchBookingReport();
//void RevenueReport(ostream& out = cout);
//void StaffReport(ostream& out = cout);
//void displayBarchart(string reportTitle, int month, int year, int weekFilter = 0, ostream& out = cout);
//void ReportExport();
//void reportingMenu();
//// ========================================
//
//int findCustomerIndex(const string& id) {
//    for (int i = 0; i < customerCount; i++)
//        if (customerDB[i].idCustomer == id) return i;
//    return -1;
//}
//
//int findMemberIndex(const string& id) {
//    for (int i = 0; i < memberCount; i++) {
//        if (memberDB[i].idMember == id) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int findStaffIndex(const string& id) {
//    for (int i = 0; i < staffCount; i++){
//        if (staffDB[i].idStaff == id) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int findServiceIndex(const string& id) {
//    for (int i = 0; i < serviceCount; i++) {
//        if (servicesDB[i].serviceID == id){
//            return i;
//        }
//    }
//    return -1;
//}
//
//int findBookingIndex(const string& id) {
//    for (int i = 0; i < bookingCount; i++) {
//        if (bookingDB[i].bookingID == id) {
//            return i;
//        }
//    }
//    return -1;
//}
//
////change
//bool validateBooking(const Bookings& booking) { 
//    if (booking.customerID.empty()) return false;
//    if (findServiceIndex(booking.serviceID) == -1) return false;
//    if (findStaffIndex(booking.staffID) == -1) return false;
//    if (booking.date.empty()) return false;
//    if (booking.time.empty()) return false;
//    if (booking.status.empty()) return false;
//    return true;
//}
//
//void viewServices() {  
//    cout << "\n========================================\n";
//    cout << right << setw(10) << "SERVICES\n";
//    cout << "========================================\n";
//    for (int i = 0; i < serviceCount; i++) {
//        const Services& services = servicesDB[i];
//        cout << "Service ID : " << services.serviceID << "\n";
//        cout << "Service    : " << services.servicename << "\n";
//        cout << "Price      : RM " << fixed << setprecision(2) << services.price << "\n";
//        cout << "Duration   : " << services.duration << " minutes\n";
//        cout << "----------------------------------------\n";
//    }
//}
//
//void addSingleBooking(const string& customerID) {  
//    Bookings sinBooking;
//    sinBooking.bookingID = "B" + to_string(bookingCounter++);
//    sinBooking.customerID = customerID;
//    sinBooking.status = "Booked";
//
//    cout << "\n========== ADD SINGLE BOOKING ==========\n";
//    viewServices();
//
//    cout << "Enter Service ID: ";
//    cin >> sinBooking.serviceID;
//    if (findServiceIndex(sinBooking.serviceID) == -1) {
//        cout << "[Error] Service ID not found.\n";
//        return;
//    }
//
//    cout << "Enter Staff ID: ";
//    cin >> sinBooking.staffID;
//    if (findStaffIndex(sinBooking.staffID) == -1) {
//        cout << "[Error] Staff ID not found.\n";
//        return;
//    }
//
//    cout << "Enter Date (DD/MM/YYYY): ";
//    cin >> sinBooking.date;
//    cout << "Enter Time (HH:MM): ";
//    cin >> sinBooking.time;
//
//    if (!validateBooking(sinBooking)) {
//        cout << "[Error] Booking validation failed.\n";
//        return;
//    }
//
//    if (bookingCount >= MAX_BOOKINGS) {
//        cout << "[Error] Booking database is full.\n";
//        return;
//    }
//
//    bookingDB[bookingCount] = sinBooking;
//    bookingCount++;    cout << "\n[Success] Booking added successfully!\n";
//    cout << "Booking ID: " << sinBooking.bookingID << "\n";
//}
//
//// use teammate data to load Appointment
//void loadSmallAppointments() {
//
//    if (bookingCount == 0) {
//        cout << "No booking data available for reporting.\n";
//        return;
//    }
//
//    for (int i = 0; i < bookingCount; i++) {
//        const Bookings& booking = bookingDB[i];
//
//        if (booking.status != "Completed" && booking.status != "Booked") {
//            continue;
//        }
//
//        int serviceIdx = findServiceIndex(booking.serviceID);
//
//        if (serviceIdx == -1) {
//            continue;
//        }
//
//        if (appointmentCount >= MAX_SIZE) {
//            cout << "Report data is full.\n";
//            return;
//        }
//
//        const Services& service = servicesDB[serviceIdx];
//        appointments[appointmentCount].appointmentId = booking.bookingID;
//
//        int custIdx = findCustomerIndex(booking.customerID);
//        if (custIdx != -1) {
//            appointments[appointmentCount].customerName = customerDB[custIdx].nameCustomer;
//        }
//        else {
//            int memIdx = findMemberIndex(booking.customerID);
//            if (memIdx != -1) {
//                appointments[appointmentCount].customerName = memberDB[memIdx].nameMember;
//            }
//            else {
//                appointments[appointmentCount].customerName = booking.customerID;
//            }
//        }
//
//        int staffIdx = findStaffIndex(booking.staffID);
//        if (staffIdx != -1) {
//            appointments[appointmentCount].staffName = staffDB[staffIdx].nameStaff;
//        }
//        else {
//            appointments[appointmentCount].staffName = booking.staffID;
//        }
//
//        appointments[appointmentCount].serviceName = service.servicename;
//        appointments[appointmentCount].quantity = 1;
//        appointments[appointmentCount].price = service.price;
//
//        if (booking.date.length() >= 10) {
//            appointments[appointmentCount].day = stoi(booking.date.substr(0, 2));
//            appointments[appointmentCount].month = stoi(booking.date.substr(3, 2));
//            appointments[appointmentCount].year = stoi(booking.date.substr(6, 4));
//        }
//        else {
//            appointments[appointmentCount].day = 1;
//            appointments[appointmentCount].month = 8;
//            appointments[appointmentCount].year = 2026;
//        }
//
//        appointments[appointmentCount].timeSlot = booking.time;
//        appointments[appointmentCount].status = booking.status;
//
//        appointmentCount++;
//    }
//}
//
//void getCurrentSystemTime(
//    int& year,
//    int& month,
//    int& day,
//    int& hour
//) {
//    time_t now = time(0);
//    tm localTime;
//
//    localtime_s(&localTime, &now);
//
//    year = 1900 + localTime.tm_year;
//    month = 1 + localTime.tm_mon;
//    day = localTime.tm_mday;
//    hour = localTime.tm_hour;
//}
//
//void loadEventAppointments() {
//    int year, month, currentDay, hour;
//    getCurrentSystemTime(year, month, currentDay, hour);
//
//    for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
//        for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
//            const Timeslot& slot = schedule[dayIndex][slotIndex];
//
//            // ???????????
//            if (!slot.isBooked) {
//                continue;
//            }
//
//            if (appointmentCount >= MAX_SIZE) {
//                cout << "Report data is full.\n";
//                return;
//            }
//
//            Appointment& report = appointments[appointmentCount];
//
//            // Timeslot ?? appointmentID?????? + slot ID ?? report ID
//            report.appointmentId =
//                "EVENT-D" + to_string(dayIndex + 1) +
//                "-S" + to_string(slot.id);
//
//            report.customerName = slot.customerName;
//            report.staffName = slot.staffName;
//            report.serviceName = slot.service;
//            report.quantity = 1;
//
//            // schedule[0] ???? 1 ?
//            report.day = dayIndex + 1;
//            report.month = month;
//            report.year = year;
//            report.timeSlot = slot.time;
//            report.status = slot.status;
//
//            // ??????????? service ????? report ??????
//            if (slot.service == "Wedding Event") {
//                report.price = 200.00;
//            }
//            else if (slot.service == "Hair dressing with make up") {
//                report.price = 150.00;
//            }
//            else {
//                report.price = 0.00;
//            }
//
//            appointmentCount++;
//        }
//    }
//}
//
//void loadDataFromTeamSystem() {
//    appointmentCount = 0;
//
//    loadSmallAppointments();
//    loadEventAppointments(); // ??????? schedule[][]
//}
//
//void SearchBookingReport() {
//    string bookingID;
//
//    cout << "\n=== SEARCH BOOKING REPORT ===\n";
//    cout << "Enter Booking ID: ";
//    cin >> bookingID;
//
//    int bookingIdx = findBookingIndex(bookingID);
//
//    if (bookingIdx == -1) {
//        cout << "Booking record not found.\n";
//        return;
//    }
//
//    const Bookings& booking = bookingDB[bookingIdx];
//
//    string customerName = booking.customerID;
//    auto itCustomer = findCustomerIndex(booking.customerID);
//
//    if (itCustomer != -1) {
//        customerName = customerDB[itCustomer].nameCustomer;
//    }
//    else {
//        auto itMember = findMemberIndex(booking.customerID);
//        if (itMember != -1) {
//            customerName = memberDB[itMember].nameMember;
//        }
//    }
//
//    string staffName = booking.staffID;
//    auto itStaff = findStaffIndex(booking.staffID);
//    if (itStaff != -1) {
//        staffName = staffDB[itStaff].nameStaff;
//    }
//
//    string serviceName = booking.serviceID;
//    double price = 0.0;
//    auto itService = findServiceIndex(booking.serviceID);
//    if (itService != -1) {
//        serviceName = servicesDB[itService].servicename;
//        price = servicesDB[itService].price;
//    }
//
//    cout << "\n========== BOOKING REPORT ==========\n";
//    cout << "Booking ID    : " << booking.bookingID << '\n';
//    cout << "Customer      : " << customerName << '\n';
//    cout << "Staff         : " << staffName << '\n';
//    cout << "Service       : " << serviceName << '\n';
//    cout << "Price         : RM " << fixed << setprecision(2) << price << '\n';
//    cout << "Date          : " << booking.date << '\n';
//    cout << "Time          : " << booking.time << '\n';
//    cout << "Status        : " << booking.status << '\n';
//
//    if (booking.status == "Completed") {
//        cout << "Revenue Count : Included\n";
//    }
//    else {
//        cout << "Revenue Count : Not included\n";
//    }
//
//    cout << "====================================\n";
//}
//// ========================================
//
//// Display Logo
//void logo() {
//    cout << R"(
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
// ######    ######       ######     ###    ##        #######  ##    ##    
//##    ##  ##    ##     ##    ##   ## ##   ##       ##     ## ###   ##    
//##        ##           ##        ##   ##  ##       ##     ## ####  ##    
//##   #### ##   ####     ######  ##     ## ##       ##     ## ## ## ##    
//##    ##  ##    ##           ## ######### ##       ##     ## ##  ####    
//##    ##  ##    ##     ##    ## ##     ## ##       ##     ## ##   ###    
// ######    ######       ######  ##     ## ########  #######  ##    ##    
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
//)" << endl;
//}
//
//// Display Barchart(revenue&staff)
//void displayBarchart(string reportTitle, int month, int year, int weekFilter, ostream& out) {
//    out << "\n=== " << reportTitle << " (BARCHART) ===" << endl;
//    out << "------------------------------------" << endl;
//    string services[MAX_SIZE];
//    double totals[MAX_SIZE] = { 0 };
//    int count = 0;
//
//    for (int i = 0; i < appointmentCount; i++) {
//        int currentWeek = (appointments[i].day - 1) / 7 + 1;
//        bool weekMatch = (weekFilter == 0) || (currentWeek == weekFilter);
//
//        if (appointments[i].status == "Booked" &&
//            appointments[i].month == month &&
//            appointments[i].year == year &&
//            weekMatch)
//        {
//            bool found = false;
//            for (int j = 0; j < count; j++) {
//                if (services[j] == appointments[i].serviceName) {
//                    totals[j] += (appointments[i].quantity * appointments[i].price);
//                    found = true;
//                    break;
//                }
//            }
//            if (!found) {
//                services[count] = appointments[i].serviceName;
//                totals[count] = appointments[i].quantity * appointments[i].price;
//                count++;
//            }
//        }
//    }
//
//    if (count == 0) {
//        out << "No completed records found for this timeframe." << endl;
//    }
//    else {
//        for (int i = 0; i < count; i++) {
//            out << left << setw(12) << services[i] << " | ";
//            int stars = (int)(totals[i] / 50);
//            for (int k = 0; k < stars; k++) out << "*";
//            out << " (RM " << fixed << setprecision(2) << totals[i] << ")" << endl;
//        }
//    }
//    out << "------------------------------------" << endl;
//}
//
//// Revenue Report--services data
//void RevenueReport(ostream& out) {
//    int targetMonth, targetYear, targetWeek;
//    cout << "\nEnter Month/Year/Week (week0 is for Monthly): ";
//    cin >> targetMonth >> targetYear >> targetWeek;
//
//    loadDataFromTeamSystem();
//
//    double totalRevenue = 0;
//    string serviceNames[MAX_SIZE];
//    int serviceQty[MAX_SIZE] = { 0 };
//    double serviceRevenue[MAX_SIZE] = { 0.0 };
//    int serviceTypeCount = 0;
//
//    out << "\n========================================================" << endl;
//    if (targetWeek > 0)
//        out << "      REVENUE REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
//    else
//        out << "      MONTHLY REVENUE REPORT FOR " << targetMonth << "/" << targetYear << endl;
//    out << "========================================================" << endl;
//    out << left << setw(10) << "ID"
//        << setw(15) << "Service"
//        << setw(8) << "Qty"
//        << setw(10) << "Price"
//        << "Total Amount" << endl;
//    out << "--------------------------------------------------------" << endl;
//
//    for (int i = 0; i < appointmentCount; i++) {
//        int currentWeek = (appointments[i].day - 1) / 7 + 1;
//        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);
//
//        if (appointments[i].status == "Booked" &&
//            appointments[i].month == targetMonth &&
//            appointments[i].year == targetYear &&
//            weekMatch) {
//
//            double amount = appointments[i].quantity * appointments[i].price;
//            totalRevenue += amount;
//
//            out << left << setw(10) << appointments[i].appointmentId
//                << setw(15) << appointments[i].serviceName
//                << setw(8) << appointments[i].quantity
//                << "RM" << setw(8) << fixed << setprecision(2) << appointments[i].price
//                << "RM " << amount << endl;
//
//            bool found = false;
//            for (int j = 0; j < serviceTypeCount; j++) {
//                if (serviceNames[j] == appointments[i].serviceName) {
//                    serviceQty[j] += appointments[i].quantity;
//                    serviceRevenue[j] += amount;
//                    found = true;
//                    break;
//                }
//            }
//            if (!found) {
//                serviceNames[serviceTypeCount] = appointments[i].serviceName;
//                serviceQty[serviceTypeCount] = appointments[i].quantity;
//                serviceRevenue[serviceTypeCount] = amount;
//                serviceTypeCount++;
//            }
//        }
//    }
//
//    out << "--------------------------------------------------------" << endl;
//    out << "TOTAL REVENUE GENERATED: RM " << fixed << setprecision(2) << totalRevenue << endl;
//    out << "========================================================" << endl;
//
//    if (serviceTypeCount > 0) {
//        int topIdx = 0;
//        for (int i = 1; i < serviceTypeCount; i++) {
//            if (serviceRevenue[i] > serviceRevenue[topIdx]) {
//                topIdx = i;
//            }
//        }
//        out << "\n*** TOP SERVICE ***" << endl;
//        out << " Highest Revenue Service: " << serviceNames[topIdx]
//            << " (Total: RM " << fixed << setprecision(2) << serviceRevenue[topIdx]
//            << ", Total Qty: " << serviceQty[topIdx] << ")" << endl;
//    }
//
//    string title = (targetWeek > 0) ? "WEEKLY REVENUE" : "MONTHLY REVENUE";
//    displayBarchart(title, targetMonth, targetYear, targetWeek, out);
//}
//
//// Staff Report--staff data
//void StaffReport(ostream& out) {
//    int targetMonth, targetYear, targetWeek;
//    cout << "\nEnter Month Year Week (week0 is for Monthly): ";
//    cin >> targetMonth >> targetYear >> targetWeek;
//
//    loadDataFromTeamSystem();
//
//    string staffNames[MAX_SIZE];
//    int serviceCounts[MAX_SIZE] = { 0 };
//    int uniqueStaff = 0;
//
//    for (int i = 0; i < appointmentCount; i++) {
//        int currentWeek = (appointments[i].day - 1) / 7 + 1;
//        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);
//
//        if (appointments[i].status == "Booked" &&
//            appointments[i].month == targetMonth &&
//            appointments[i].year == targetYear && weekMatch)
//        {
//            bool found = false;
//            for (int j = 0; j < uniqueStaff; j++) {
//                if (staffNames[j] == appointments[i].staffName) {
//                    serviceCounts[j] += appointments[i].quantity;
//                    found = true;
//                    break;
//                }
//            }
//            if (!found) {
//                staffNames[uniqueStaff] = appointments[i].staffName;
//                serviceCounts[uniqueStaff] = appointments[i].quantity;
//                uniqueStaff++;
//            }
//        }
//    }
//
//    out << "\n=== STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear;
//    if (targetWeek > 0) out << " (WEEK " << targetWeek << ")";
//    out << " ===" << endl;
//    out << "------------------------------------" << endl;
//    out << left << setw(15) << "Staff Name" << "Services Handled" << endl;
//    out << "------------------------------------" << endl;
//
//    if (uniqueStaff == 0) {
//        out << "No staff workload found for this timeframe." << endl;
//    }
//    else {
//        for (int i = 0; i < uniqueStaff; i++) {
//            out << left << setw(15) << staffNames[i] << serviceCounts[i] << endl;
//        }
//    }
//    out << "------------------------------------" << endl;
//
//    out << "\n=== STAFF WORKLOAD (BARCHART) ===" << endl;
//    for (int i = 0; i < uniqueStaff; i++) {
//        out << left << setw(10) << staffNames[i] << " | ";
//        for (int k = 0; k < serviceCounts[i]; k++) out << "*";
//        out << " (" << serviceCounts[i] << " services)" << endl;
//    }
//    out << "------------------------------------" << endl;
//}
//
//// Report Export
//void ReportExport() {
//    int exportChoice;
//    cout << "\n=== REPORT EXPORT ===" << endl;
//    cout << "1. Export Revenue Report" << endl;
//    cout << "2. Export Staff Report" << endl;
//    cout << "Please select report type to export: ";
//    cin >> exportChoice;
//
//    if (exportChoice != 1 && exportChoice != 2) {
//        cout << "Invalid choice." << endl;
//        return;
//    }
//
//    ofstream outFile("report_export.txt");
//    if (!outFile.is_open()) {
//        cout << "--> File output error!" << endl;
//        return;
//    }
//
//    if (exportChoice == 1) {
//        RevenueReport(outFile);
//    }
//    else {
//        StaffReport(outFile);
//    }
//
//    outFile.close();
//    cout << "\n--> Report printed successfully!" << endl;
//}
//
//// Display Menu
//void reportingMenu() {
//    cout << "\n========================================" << endl;
//    cout << "        REPORTING SYSTEM                " << endl;
//    cout << "========================================" << endl;
//    cout << "1. Search Booking Report" << endl;
//    cout << "2. Revenue Report (Weekly / Monthly)" << endl;
//    cout << "3. Staff Report (Weekly / Monthly)" << endl;
//    cout << "4. Report Export" << endl;
//    cout << "0. Exit" << endl;
//    cout << "Please choose an option: ";
//}
//
//// MAIN
//int main() {
//    logo();
//
//
//    loadDataFromTeamSystem();
//
//    cout << "\n[System] Team data loaded successfully!" << endl;
//    cout << "[System] Services: " << serviceCount
//        << " | Staff: " << staffCount
//        << " | Appointments: " << appointmentCount << endl;
//
//    int option;
//    do {
//        reportingMenu();
//        cin >> option;
//
//        switch (option) {
//
//        case 1:
//            SearchBookingReport();
//            break;
//        case 2:
//            RevenueReport();
//            break;
//        case 3:
//            StaffReport();
//            break;
//        case 4:
//            ReportExport();
//            break;
//        case 0:
//            cout << "\nExiting program. Goodbye!" << endl;
//            break;
//        default:
//            cout << "\nInvalid option. Please try again." << endl;
//            break;
//        }
//
//        if (option >= 1 && option <= 4) {
//            cout << "\nPress Enter to return to menu...";
//            cin.ignore();
//            cin.get();
//        }
//
//    } while (option != 0);
//
//    return 0;
//}