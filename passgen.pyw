import random
import string
import tkinter as tk
from tkinter import messagebox
import os 

def generate_password(length=12):
    characters = string.ascii_letters + string.digits + string.punctuation
    password = ''.join(random.choice(characters) for i in range(length))
    return password

def ensure_file_exists(filename):
    if not os.path.exists(filename):
        with open(filename, "w") as file:
            pass  

def save_password_to_file(name, password):
    filename = "passlog.txt"
    ensure_file_exists(filename)  
    with open(filename, "a") as file:
        file.write(f"{name}: {password}\n")

def generate_and_save_password():
    name = name_entry.get()
    password_length = int(length_entry.get())
    generated_password = generate_password(password_length)
    save_password_to_file(name, generated_password)
    messagebox.showinfo("Password Created", "Password created and saved in passlog.txt")


window = tk.Tk()
window.title("Password Generator")
window.resizable(False, False)
window.geometry("200x200")

name_label = tk.Label(window, text="Name:")
name_label.grid(row=0, column=0, padx=5, pady=5)
name_entry = tk.Entry(window)
name_entry.grid(row=0, column=1, padx=5, pady=5)

length_label = tk.Label(window, text="Length:")
length_label.grid(row=1, column=0, padx=5, pady=5)
length_entry = tk.Entry(window)
length_entry.grid(row=1, column=1, padx=5, pady=5)

generate_button = tk.Button(window, text="Create", command=generate_and_save_password)
generate_button.grid(row=2, column=0, columnspan=2, padx=5, pady=5)

window.mainloop()
