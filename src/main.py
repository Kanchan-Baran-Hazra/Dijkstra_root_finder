from fastapi import FastAPI
from src.api.service import service_route

version="v10"

app=FastAPI(
    version=version,
    title="Path finder app",
    description="This app is give the path from some source to destinatin with total distance in KM and the time.",
)

@app.get("/")
async def health():
    return {"response":"OK","message":"Server is running..."}


app.include_router(service_route,prefix=f"/api/{version}/service",tags=['Service'])