//#include <iostream>
//#include <fstream>
//#include <string>
//#include <iomanip>
//using namespace std;
//
//const int MAX_SIZE = 100;
//
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
//// ===== demo data =====
//void setDemoData(int month = 8, int year = 2026) {
//    appointmentCount = 7;
//    appointments[0] = { "1", "Customer A", "John Tan", "Haircut", 2, 50.00, 5, month, year, "09:00 AM - 10:00 AM", "Completed" };
//    appointments[1] = { "2", "Customer B", "John Tan", "Haircut", 1, 50.00, 10, month, year, "10:00 AM - 11:00 AM", "Completed" };
//    appointments[2] = { "3", "Customer C", "Alice Lim", "Massage", 1, 150.00, 10, month, year, "11:00 AM - 12:00 PM", "Completed" };
//    appointments[3] = { "4", "Customer D", "Alice Lim", "Facial", 1, 120.00, 10, month, year, "01:00 PM - 02:00 PM", "Completed" };
//    appointments[4] = { "5", "Customer E", "John Tan", "Facial", 1, 120.00, 18, month, year, "02:00 PM - 03:00 PM", "Completed" };
//    appointments[5] = { "6", "Customer F", "Alice Lim", "Manicure", 2, 30.00, 25, month, year, "03:00 PM - 04:00 PM", "Completed" };
//    appointments[6] = { "7", "Customer G", "John Tan", "Haircut", 1, 50.00, 25, month, year, "04:00 PM - 05:00 PM", "Completed" };
//}
//
//// ===== Display Logo =====
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
//// ===== Display Menu =====
//void menu() {
//    cout << "\nWelcome to the Reporting System!\n" << endl;
//    cout << "1. Revenue Report (Weekly / Monthly)" << endl;
//    cout << "2. Staff Report (Weekly / Monthly)" << endl;
//    cout << "3. Report Export" << endl;
//    cout << "0. End the program\n" << endl;
//    cout << "Please choose an option: ";
//}
//
//// ===== Display Barchart =====
//void displayBarchart(string reportTitle, int month, int year, int weekFilter = 0, ostream& out = cout) {
//    out << "\n=== " << reportTitle << " (BARCHART) ===" << endl;
//    out << "------------------------------------" << endl;
//    string services[MAX_SIZE];
//    double totals[MAX_SIZE] = { 0 };
//	int count = 0; // Count of services
//
//    for (int i = 0; i < appointmentCount; i++) {
//        int currentWeek = (appointments[i].day - 1) / 7 + 1;
//        bool weekMatch = (weekFilter == 0) || (currentWeek == weekFilter);
//
//        if (appointments[i].status == "Completed" && appointments[i].month == month && appointments[i].year == year && weekMatch) 
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
//	else {          //draw bar chart
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
//// ===== RevenueReport =====
//void RevenueReport(ostream& out = cout) {
//    int targetMonth, targetYear, targetWeek;
//    cout << "\nEnter Month/Year/Week (week0 is for Monthly): ";
//    cin >> targetMonth >> targetYear >> targetWeek;
//
//    setDemoData(targetMonth, targetYear);
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
//        if (appointments[i].status == "Completed" &&
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
//// ===== StaffReport =====
//void StaffReport(ostream& out = cout) {
//    int targetMonth, targetYear, targetWeek;
//    cout << "\nEnter Month Year Week (week0 is for Monthly): ";
//    cin >> targetMonth >> targetYear >> targetWeek;
//
//    setDemoData(targetMonth, targetYear);
//
//    string staffNames[MAX_SIZE];
//    int serviceCounts[MAX_SIZE] = { 0 };
//    int uniqueStaff = 0;
//
//    for (int i = 0; i < appointmentCount; i++) {
//        int currentWeek = (appointments[i].day - 1) / 7 + 1;
//        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);
//
//        if (appointments[i].status == "Completed" &&
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
//// ===== ReportExport =====
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
//    // use outFile to call out
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
//// ============================================
//// MAIN
//// ============================================
//int main() {
//    logo();
//
//    int option;
//    do {
//        menu();
//        cin >> option;
//
//        switch (option) {
//        case 1:
//            RevenueReport();
//            break;
//        case 2:
//            StaffReport();
//            break;
//        case 3:
//            ReportExport();
//            break;
//        case 0:
//            cout << "\nExiting the program. Thank you!" << endl;
//            break;
//        default:
//            cout << "\nInvalid option. Please try again." << endl;
//            break;
//        }
//
//        if (option == 1 || option == 2 || option == 3) {
//            cout << "\nPress Enter to return to menu...";
//            cin.ignore();
//            cin.get();
//        }
//
//    } while (option != 0);
//
//    return 0;
//}