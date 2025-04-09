from PyPDF2 import PdfReader

# Specify the path to your PDF file
pdf_file_path = "./main.pdf"

# Create a PDF reader object
reader = PdfReader(pdf_file_path)

# Extract text from all pages and format it in one step
formatted_text = ""
for page in reader.pages:
    formatted_text += " ".join(page.extract_text().splitlines()) + " "

# Print the formatted text
print(formatted_text)

