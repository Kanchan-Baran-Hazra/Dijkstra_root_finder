from fastapi import FastAPI
from src.api.service import service_route
from fastapi.middleware.cors import CORSMiddleware

version="v10"

app=FastAPI(
    version=version,
    title="Path finder app",
    description="This app is give the path from some source to destinatin with total distance in KM and the time.",
)

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

@app.get("/")
async def health():
    return {"response":"OK","message":"Server is running..."}


app.include_router(service_route,prefix=f"/api/{version}/service",tags=['Service'])