import tkinter as tk
from tkinter import messagebox

# Data will be stored in a list of dictionaries
students = []

# Function Definitions
def add_student():
    roll = roll_var.get()
    name = name_var.get()
    marks = marks_var.get()

    if not roll or not name or not marks:
        messagebox.showerror("Input Error", "All fields are required!")
        return

    for student in students:
        if student['roll'] == roll:
            messagebox.showerror("Error", "Roll number already exists.")
            return

    students.append({'roll': roll, 'name': name, 'marks': marks})
    messagebox.showinfo("Success", "Student added successfully!")
    clear_fields()

def display_all():
    listbox.delete(0, tk.END)
    for student in students:
        listbox.insert(tk.END, f"{student['roll']} - {student['name']} - {student['marks']}")

def search_student():
    roll = roll_var.get()
    for student in students:
        if student['roll'] == roll:
            name_var.set(student['name'])
            marks_var.set(student['marks'])
            return
    messagebox.showinfo("Not Found", "Student not found.")

def update_student():
    roll = roll_var.get()
    for student in students:
        if student['roll'] == roll:
            student['name'] = name_var.get()
            student['marks'] = marks_var.get()
            messagebox.showinfo("Updated", "Student record updated.")
            return
    messagebox.showerror("Error", "Roll number not found.")

def delete_student():
    roll = roll_var.get()
    for i, student in enumerate(students):
        if student['roll'] == roll:
            del students[i]
            messagebox.showinfo("Deleted", "Student record deleted.")
            clear_fields()
            return
    messagebox.showerror("Error", "Roll number not found.")

def clear_fields():
    roll_var.set("")
    name_var.set("")
    marks_var.set("")

# GUI Setup
app = tk.Tk()
app.title("Student Record System")
app.geometry("500x500")

roll_var = tk.StringVar()
name_var = tk.StringVar()
marks_var = tk.StringVar()

# Input Labels & Entries
tk.Label(app, text="Roll No").pack()
tk.Entry(app, textvariable=roll_var).pack()

tk.Label(app, text="Name").pack()
tk.Entry(app, textvariable=name_var).pack()

tk.Label(app, text="Marks").pack()
tk.Entry(app, textvariable=marks_var).pack()

# Buttons
tk.Button(app, text="Add Student", command=add_student).pack(pady=5)
tk.Button(app, text="Display All", command=display_all).pack(pady=5)
tk.Button(app, text="Search", command=search_student).pack(pady=5)
tk.Button(app, text="Update", command=update_student).pack(pady=5)
tk.Button(app, text="Delete", command=delete_student).pack(pady=5)

# Listbox to show students
listbox = tk.Listbox(app, width=50)
listbox.pack(pady=10)

app.mainloop()
