const mongoose = require("mongoose");

const metricsSchema = new mongoose.Schema({
    searchTerm: {
        type: String,
        required: true,
    },
    count: {
        type: Number,
        default: 1,
    },
    poster_url: {
        type: String,
        required: true,
    },
    movie_id: {
        type: Number,
        required: true,
    }
});

module.exports = mongoose.model("Metrics", metricsSchema);
