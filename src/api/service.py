from fastapi import APIRouter,HTTPException,status
from fastapi.responses import JSONResponse
import subprocess
import json
from pathlib import Path
import os


service_route=APIRouter()

# Builds a cross-platform path relative to your project root
BASE_DIR = Path(__file__).resolve().parent.parent  # Adjust depending on where script lives
# print(BASE_DIR)
FILE_PATH = Path(BASE_DIR / "engine" / "algo_linux")
# print(FILE_PATH)

# Ensure the executable has execution permissions on Linux
# Run this once or via command line: os.chmod(FILE_PATH, 0o755)
# Grant read, write, and execute permissions (chmod +x equivalent)
if FILE_PATH.exists():
    os.chmod(FILE_PATH, 0o755)

@service_route.get('/stations')
async def get_stations():
    try:
        result=subprocess.run(
            [str(FILE_PATH),"","","1"],                      # 1 for get the all station names
            capture_output=True,
            text=True,
            check=True
        )
        
        # print(result.stdout)
        data=json.loads(result.stdout)
        return JSONResponse(
            content=json.loads(result.stdout),
            status_code=status.HTTP_200_OK
        )
    except subprocess.CalledProcessError as e:
        return HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail=f"error: {e.stderr}"
        )
    except Exception as e:
        return HTTPException(
            status_code=status.HTTP_500_INTERNAL_SERVER_ERROR,
            detail=f"Error: {e}"
        )

@service_route.get("/path")
async def get_path(source:str,destination:str):
    try:
        l=source.split()
        s=[]
        for i in l:
            s.append(i.capitalize())
        source="_".join(l)
        # source=source.capitalize()

        l=destination.split()
        for i in l:
            s.append(i.capitalize())
        destination="_".join(l)
        # destination=destination.capitalize()

        result=subprocess.run(
            [FILE_PATH,source,destination,"2"],                      # 1 for get the all station names
            capture_output=True,
            text=True,
            check=True
        )
        
        # print(result.stdout)
        # data=json.loads(result.stdout)
        return JSONResponse(
            content=json.loads(result.stdout),
            status_code=status.HTTP_200_OK
        )
    except subprocess.CalledProcessError as e:
        return HTTPException(
            status_code=status.HTTP_400_BAD_REQUEST,
            detail=f"error: {e.stderr}"
        )
    except Exception as e:
        return HTTPException(
            status_code=status.HTTP_500_INTERNAL_SERVER_ERROR,
            detail=f"Error: {e}"
        )