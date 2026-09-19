import subprocess
import json


# test api

try:
    result=subprocess.run(
        ["a.exe","Alipurduar","Raghunathpur","2"],
        capture_output=True,
        text=True,
        check=True
    )
    
    # print(result.stdout)
    data=json.loads(result.stdout)
    print(json.dumps(data))
except subprocess.CalledProcessError as e:
    print(f"error: {e.stderr}")
except Exception as e:
    print(f"Error: {e}")