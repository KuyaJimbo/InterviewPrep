import os

# Get the current directory
current_directory = os.getcwd()

# List all files in the current directory
files_in_directory = os.listdir(current_directory)

# Loop through the files and remove any .exe files
for file_name in files_in_directory:
    if file_name.endswith(".exe"):
        file_path = os.path.join(current_directory, file_name)
        try:
            os.remove(file_path)
            print(f"Removed: {file_name}")
        except Exception as e:
            print(f"Error removing {file_name}: {e}")
