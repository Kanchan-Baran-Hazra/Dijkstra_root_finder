
const API_BASE_URL = "https://dijkstra-root-finder-1.onrender.com/api/v10/service"
const sourceSelect = document.getElementById("source");
const destinationSelect = document.getElementById("destination");

const findRouteButton = document.getElementById("findRoute");

const loading = document.getElementById("loading");
const error = document.getElementById("error");
const result = document.getElementById("result");

const routeElement = document.getElementById("route");
const distanceElement = document.getElementById("distance");


async function loadStations() {

    try {

        const response = await fetch(
            `${API_BASE_URL}/stations`
        );

        if (!response.ok) {
            throw new Error("Failed to load stations");
        }

        const data = await response.json();

        data.choice.forEach(station => {

            const sourceOption = document.createElement("option");
            sourceOption.value = station;
            sourceOption.textContent = station;

            sourceSelect.appendChild(sourceOption);


            const destinationOption = document.createElement("option");
            destinationOption.value = station;
            destinationOption.textContent = station;

            destinationSelect.appendChild(destinationOption);
        });

    } catch (err) {

        console.error(err);

        error.textContent = "Unable to load metro stations.";
        error.classList.remove("hidden");
    }
}

findRouteButton.addEventListener("click", findRoute);


async function findRoute() {

    const source = sourceSelect.value;
    const destination = destinationSelect.value;

    // Validate selection
    if (!source || !destination) {
        error.textContent = "Please select both stations.";
        error.classList.remove("hidden");
        return;
    }

    // Same station
    if (source === destination) {
        error.textContent = "Source and destination cannot be the same.";
        error.classList.remove("hidden");
        return;
    }

    // Show loading
    error.classList.add("hidden");
    result.classList.add("hidden");
    loading.classList.remove("hidden");


    try {

        const response = await fetch(
            `${API_BASE_URL}/path?source=${encodeURIComponent(source)}&destination=${encodeURIComponent(destination)}`
        );

        if (!response.ok) {
            throw new Error("Failed to find route");
        }

        const data = await response.json();

        console.log(data);

        // Display route
        routeElement.innerHTML = "";

        data.path.forEach((station, index) => {

            const stationElement = document.createElement("span");

            stationElement.className = "station";
            stationElement.textContent = station;

            routeElement.appendChild(stationElement);


            // Add arrow between stations
            if (index < data.path.length - 1) {

                const arrow = document.createElement("span");

                arrow.className = "arrow";
                arrow.textContent = "→";

                routeElement.appendChild(arrow);
            }
        });


        // Display distance and time
        distanceElement.innerHTML = `
            <div>
                <span>Distance</span>
                <strong>${data.distance_km} km</strong>
            </div>

            <div>
                <span>Time</span>
                <strong>${data.time_min} min</strong>
            </div>
        `;


        result.classList.remove("hidden");

    } catch (err) {

        console.error(err);

        error.textContent = "Unable to find the route.";
        error.classList.remove("hidden");

    } finally {

        loading.classList.add("hidden");
    }
}



loadStations();

