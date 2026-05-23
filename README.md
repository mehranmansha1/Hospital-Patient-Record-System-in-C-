# 🏥 Hospital Patient Record System — C++

A fully functional **console-based Hospital Patient Record System** built in C++ that simulates real-world hospital data management. Features secure authentication, complete patient CRUD operations, appointment scheduling, and persistent file storage — all without a database.

---

## 📋 Table of Contents

- [Features](#-features)
- [Demo](#-demo)
- [Project Structure](#-project-structure)
- [Concepts Used](#-concepts-used)
- [How to Run](#-how-to-run)
- [File Storage Structure](#-file-storage-structure)
- [Functions Overview](#-functions-overview)
- [What I Learned](#-what-i-learned)
- [Future Improvements](#-future-improvements)
- [Author](#-author)

---

## ✅ Features

### 🔐 Authentication
- User **Registration** with duplicate username prevention
- Secure **Login** with credential verification
- Session management with **Logout**

### 👤 Patient Management (Full CRUD)
- ➕ **Add Patient** — with duplicate Patient ID validation
- 👁️ **View All Patients** — displays all records in formatted output
- 🔍 **Search Patient** — search by Patient ID
- ✏️ **Update Patient** — edit any field of an existing record
- 🗑️ **Delete Patient** — remove a patient record permanently

### 🗓️ Appointment System
- Book appointments with patient name, doctor name & date
- Appointments saved persistently to a separate file

### 💾 Data Persistence
- All data saved to flat files — survives program restart
- Three separate files: `users.txt`, `patients.txt`, `appointments.txt`

---

## 🎬 Demo

```
========== Hospital Patient Record System ==========

1. Register
2. Login
3. Exit

Enter Choice: 2

Enter Username: admin
Enter Password: 1234

Login Successful.

========== MAIN MENU ==========
1. Add Patient
2. View Patients
3. Search Patient
4. Update Patient
5. Delete Patient
6. Appointment System
7. Logout

Enter Choice: 1

Enter Patient ID: 101
Enter Patient Name: Ali Ahmed
Enter Age: 35
Enter Gender: Male
Enter Disease: Fever
Enter Doctor Name: Dr. Hassan
Enter Appointment Date: 25-05-2025

Patient Added Successfully.
```

---

## 📁 Project Structure

```
Hospital-Patient-Record-System/
│
├── main.cpp              # Main source code
├── users.txt             # Stores registered usernames & passwords
├── patients.txt          # Stores all patient records
├── appointments.txt      # Stores appointment records
└── README.md             # Project documentation
```

---

## 🛠️ Concepts Used

| Concept | Usage in Project |
|---|---|
| `struct` | Custom `Patient` data type with 7 fields |
| File Handling (`fstream`) | Read/write all data to flat files |
| `getline()` with delimiter | Parsing pipe-separated records (`\|`) |
| Temp file swap technique | Safe update & delete without a database |
| `atoi()` | String to integer conversion from file reads |
| Modular functions | 8 independent functions for clean design |
| Duplicate validation | Checked before every write operation |
| Nested `while` loops | Session & menu management |
| `ios::app` | Append mode for adding new records |
| `remove()` & `rename()` | File replacement after update/delete |

---

## ▶️ How to Run

### Requirements
- Any C++ compiler (GCC, MinGW, MSVC)
- IDE: Dev C++, VS Code, Code::Blocks, or any terminal

### Steps

**Option 1 — Using Dev C++ / Code::Blocks:**
1. Open `main.cpp` in your IDE
2. Click **Compile & Run**

**Option 2 — Using Terminal (GCC):**
```bash
# Compile
g++ main.cpp -o hospital

# Run
./hospital        # Linux/Mac
hospital.exe      # Windows
```

> ⚠️ Make sure `users.txt`, `patients.txt`, and `appointments.txt` are in the **same directory** as the executable. They will be created automatically on first run.

---

## 🗂️ File Storage Structure

### `users.txt`
```
username password
admin mehran
mehran mehran
```

### `patients.txt`
```
patientID|name|age|gender|disease|doctor|appointmentDate
101|Ali Ahmed|35|Male|Fever|Dr. Hassan|25-05-2025
102|Sara Khan|28|Female|Flu|Dr. Ayesha|26-05-2025
```

### `appointments.txt`
```
patientName|doctorName|date
Ali Ahmed|Dr. Hassan|25-05-2025
```

---

## 🔧 Functions Overview

| Function | Description |
|---|---|
| `main()` | Entry point — handles login/register menu & session |
| `registerUser()` | Registers new user with duplicate check |
| `login()` | Verifies credentials, returns `true`/`false` |
| `addPatient()` | Adds new patient record with duplicate ID check |
| `viewPatients()` | Displays all patient records from file |
| `searchPatient()` | Finds and displays a patient by ID |
| `updatePatient()` | Updates existing patient record using temp file |
| `deletePatient()` | Deletes a patient record using temp file swap |
| `appointmentSystem()` | Books and saves a new appointment |

---

## 📚 What I Learned

- How to use `struct` to organize related data into a single custom type
- How to implement the **temp file swap technique** for updating and deleting records without a database
- How to parse structured file data using `getline()` with custom delimiters
- How to build a **multi-level menu system** with session management
- How real **EHR (Electronic Health Record)** systems work at a foundational level
- Importance of **duplicate validation** before every write operation

---

## 🚀 Future Improvements

- [ ] Migrate to **OOP** with classes instead of structs
- [ ] Add **password hashing** for secure authentication
- [ ] Integrate **SQLite** database for scalable storage
- [ ] Add **patient billing** module
- [ ] Build a **GUI** using Qt or a web frontend
- [ ] Add **search by name** in addition to ID

---

## 👨‍💻 Author

**Mehran Mansha**
- 🎓 BS Computer Science — University of Central Punjab (UCP), Lahore
- 💼 [LinkedIn](https://www.linkedin.com/in/mehranmansha1)
- 🐙 [GitHub](https://github.com/mehranmansha1)
- 📍  Gujranwala, Pakistan

---

## ⭐ Support

If you found this project helpful or interesting, please give it a **star ⭐** on GitHub — it means a lot and motivates me to keep building!

---

> *"Every expert was once a beginner. Every pro was once an amateur."*
