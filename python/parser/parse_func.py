import re
import sys

def validate_args():
  if len(sys.argv) != 2:
    print(f"Usage: {sys.argv[0]} FILE_PATH")
    sys.exit(1)
  
  file_path = sys.argv[1]
  if not file_path.endswith('.c'):
    print("Error: Invalid file extension")
    sys.exit(1)

  return file_path

def parse_c_file(file_path):
  with open(file_path, 'r') as f:
    code = f.read()

  functions = parse_functions(code)
  return functions

def parse_functions(code):
  functions = []
  pattern = r'^(\w+\s+)+(\w+)\s*\((.*)\)\s*\{'

  matches = re.finditer(pattern, code, re.M)

  for match in matches:
    functions.append(match.group(2))

  return functions

def main():
  file_path = validate_args()
  functions = parse_c_file(file_path)
  
  for function in functions:
    print(function)

if __name__ == '__main__':
  main()
