import subprocess

try:
    result=subprocess.run(
        ["a.exe","kelogoda","sonakhali"],
        capture_output=True,
        text=True,
        check=True
    )
    
    print(result.stdout)
except subprocess.CalledProcessError as e:
    print(f"error: {e.stderr}")
except Exception as e:
    print(f"Error: {e}")