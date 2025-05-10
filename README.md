# Organized - Laboratory Component Manager

![C](https://img.shields.io/badge/Language-C-blue)

A command-line tool to efficiently manage and organize laboratory components and devices.

## Overview

Organized is a powerful C program designed to help laboratory technicians and researchers keep track of their equipment and devices. It provides an intuitive interface to manage components through basic CRUD operations and advanced sorting capabilities.

## Features

- **Add Components**: Register new devices with unique IDs, names and types:
  - ACTUATOR
  - DEVICE
  - PROCESSOR  
  - SENSOR
  - WIRE

- **Remove Components**: Delete components by their ID

- **Display**: View all registered components in a clear format

- **Sort**: Order components using merge sort algorithm by:
  - ID
  - NAME  
  - TYPE
  - Support for reverse sorting with `-r` flag

## Usage

```bash
# Build the project
make

# Run the program 
./organized
```

### Commands

```bash
# Add new components
> add TYPE NAME [TYPE NAME ...]
DEVICE n°0 - "Component1" added.

# Remove component by ID  
> del ID [ID ...]
SENSOR n°2 - "Temperature" deleted.

# Display all components
> disp
ACTUATOR n°0 - "Motor"
SENSOR n°1 - "Light"

# Sort components
> sort TYPE                # Sort by type
> sort -r NAME            # Sort by name in reverse
> sort TYPE NAME ID       # Sort by multiple criteria
```

## Development

- Written in C
- Uses linked lists for data storage
- Implements merge sort for efficient sorting
- Unit tested with Criterion framework

### Build Commands

```bash
make          # Build program
make debug    # Build with debug symbols
make tests_run    # Run unit tests
make clean    # Clean build files
make fclean   # Full clean
make re       # Rebuild all
```

## Testing

The project includes extensive unit tests using the Criterion framework:

```bash
make tests_run    # Run tests
make show_test    # Generate and show coverage report
```
