# Use Python 3.13 to match your local environment
FROM python:3.13-slim

# Install g++ compiler inside the container
RUN apt-get update && apt-get install -y g++ build-essential && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy dependency requirements and install
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copy project source files
COPY . .

# Compile the C++ binary inside the target deployment environment
RUN g++ -O3 src/engine/algo.cpp -o src/engine/algo_linux && chmod +x src/engine/algo_linux

# Expose port and launch FastAPI app
EXPOSE 8000
CMD ["uvicorn", "src.main:app", "--host", "0.0.0.0", "--port", "8000"]