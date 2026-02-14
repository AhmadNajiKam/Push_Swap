#!/bin/bash

# Check if c_formatter_42 is installed
if ! command -v c_formatter_42 &>/dev/null; then
  echo "Error: c_formatter_42 could not be found."
  echo "Install it using: pip install c_formatter_42"
  exit 1
fi

echo "Formatting all .c and .h files in the current directory..."

# Find and format files
# -maxdepth 1 limits it to the current folder (remove if you want recursive)
find . -maxdepth 1 -name "*.c" -o -name "*.h" | while read -r file; do
  echo "Processing: $file"
  c_formatter_42 <"$file" >"${file}.tmp" && mv "${file}.tmp" "$file"
done

echo "Done! All files have been formatted."
