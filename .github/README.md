# GitHub Actions CI/CD for libopencm3

This directory contains GitHub Actions workflows for continuous integration and documentation building.

## Workflows

### 1. Build Check (`build.yml`)
- **Triggers**: Push/PR to main branches
- **Purpose**: Quick build verification
- **Features**:
  - Installs ARM toolchain
  - Builds libopencm3
  - Runs style checks
  - Runs linker tests

### 2. Comprehensive CI (`comprehensive-ci.yml`)
- **Triggers**: Push/PR to main branches, weekly schedule
- **Purpose**: Extensive testing across multiple environments
- **Features**:
  - Tests on Ubuntu 20.04, 22.04, and latest
  - Matrix build for specific targets (STM32, LPC, SAM, etc.)
  - Parallel building with verbose output
  - Clean build verification

### 3. Documentation (`docs.yml`)
- **Triggers**: Push/PR to main branches
- **Purpose**: Build and verify documentation
- **Features**:
  - Installs Doxygen and dependencies
  - Builds HTML documentation
  - Uploads documentation artifacts

### 4. Status Badge (`badge.yml`)
- **Triggers**: Completion of other workflows
- **Purpose**: Update build status information
- **Features**:
  - Tracks build success/failure
  - Provides artifacts for status reporting

## Requirements

The workflows automatically install:
- `gcc-arm-none-eabi` - ARM cross-compiler toolchain
- `doxygen` - Documentation generator
- `graphviz` - Graph visualization for docs
- `python3` - For build scripts

## Supported Targets

The comprehensive CI tests these specific targets:
- STM32 families: F1, F4, F7, L4
- LPC43xx/M4
- SAM 3X

## Local Testing

To run the same checks locally:

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install gcc-arm-none-eabi doxygen graphviz python3

# Build all targets
make -j$(nproc)

# Run style checks
make stylecheck

# Run linker tests
make genlinktests

# Build documentation
cd doc && make html
```

## Contributing

When adding new targets or modifying the build system:
1. Update the target matrix in `comprehensive-ci.yml` if needed
2. Ensure new targets build successfully in CI
3. Update documentation if build requirements change
