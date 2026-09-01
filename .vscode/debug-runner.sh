#!/usr/bin/env bash
set -e

program="$1"
input_file="$2"
output_file="$3"

exec "$program" < "$input_file" > "$output_file"
