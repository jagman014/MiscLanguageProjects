const express = require("express");
const router = express.Router();
const Metrics = require("./models/Metrics");

// CREATE
router.post("/metrics", async (req, res) => {
    try {
        const newMetrics = await Metrics.create(req.body);
        res.status(201).json(newMetrics);
    } catch (error) {
        res.status(400).json({ error: req.body });
    }
});

// READ ALL
router.get("/metrics", async (req, res) => {
    try {
        const limit = req.query.limit;
        const desc = req.query.sort;

        const metrics = await Metrics.find({}).limit(limit).sort({ count: desc });
        res.status(200).json(metrics);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// READ ONE
router.get("/metrics/:id", async (req, res) => {
    try {
        const metric = await Metrics.findOne({ searchTerm: req.params.id }).exec();
        if (!metric) return res.status(404).json({ error: "Metrics not found" });
        res.status(200).json(metric);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

// UPDATE
router.put("/metrics/:id", async (req, res) => {
    try {
        const updatedMetrics = await Metrics.findOneAndUpdate({ searchTerm: req.params.id }, req.body, {
            new: true,
        });
        if (!updatedMetrics) return res.status(404).json({ error: "Metrics not found" });
        res.status(200).json(updatedMetrics);
    } catch (error) {
        res.status(400).json({ error: error.message });
    }
});

// DELETE
router.delete("/metrics/:id", async (req, res) => {
    try {
        const deletedMetrics = await Metrics.findByIdAndDelete(req.params.id);
        if (!deletedMetrics) return res.status(404).json({ error: "Metrics not found" });
        res.status(200).json(deletedMetrics);
    } catch (error) {
        res.status(500).json({ error: error.message });
    }
});

module.exports = router;
