const API_URL = import.meta.env.VITE_API_URL;

export const updateSearchCount = async (searchTerm, movie) => {
    try {
        const response = await fetch(`${API_URL}/metrics/${searchTerm}`, {
            method: 'GET',
            headers: {
                accept: "application/json",
            },
        });

        const data = await response.json();

        if (response.status === 200) {
            await fetch(`${API_URL}/metrics/${searchTerm}`, {
                method: 'PUT',
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify({
                    searchTerm: searchTerm,
                    count: data.count + 1,
                    poster_url: `https://image.tmdb.org/t/p/w500/${movie.poster_path}`,
                    movie_id: movie.id,
                })
            });
        } else {
            await fetch(`${API_URL}/metrics`, {
                method: 'POST',
                headers: {
                    "Content-Type": "application/json",
                },
                body: JSON.stringify({
                    searchTerm: searchTerm,
                    count: 1,
                    poster_url: `https://image.tmdb.org/t/p/w500/${movie.poster_path}`,
                    movie_id: movie.id,
                })
            })
        }

    } catch (error) {
        console.error(error);
    }
}

export const getTrendingMovies = async () => {
    try {
        const response = await fetch(`${API_URL}/metrics?limit=5&sort=-1`, {
            method: 'GET',
            headers: {
                accept: "application/json"
            }
        });

        return await response.json();
    } catch (error) {
        console.error(error);
    }
}
