import random

# Function to generate student records
def generate_student_records(num_students):
    students = []
    for i in range(num_students):
        student_id = i + 1  # Ensure unique and sorted IDs
        name = f"Student_{i+1}"
        age = random.randint(18, 25)
        gpa = round(random.uniform(2.0, 4.0), 2)
        students.append((student_id, name, age, gpa))
    return students

# Function to write student records to a file
def write_students_file(students, filename):
    with open(filename, "w") as file:
        file.write(f"{len(students)}\n")
        for student_id, name, age, gpa in students:
            file.write(f"{student_id},{name},{age},{gpa}\n")

if __name__ == "__main__":
    num_students = int(input("Enter the number of students: "))
    
    students = generate_student_records(num_students)
    
    filename = f"students_{num_students}.txt"
    
    write_students_file(students, filename)
    
    print(f"Generated {num_students} student records in '{filename}'.")
