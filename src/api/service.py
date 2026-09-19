from fastapi import APIRouter,HTTPException,status
from fastapi.responses import JSONResponse
import subprocess
import json


service_route=APIRouter()

FILE_PATH=r"src\engine\a.exe"

@service_route.get('/stations')
async def get_stations():
    try:
        result=subprocess.run(
            [FILE_PATH,"","","1"],                      # 1 for get the all station names
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

@service_route.post("/path")
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