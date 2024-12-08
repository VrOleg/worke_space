/**
 * @swagger
 * components:
 *   schemas:
 *     user:
 *       type: object
 *       required:
 *         - email
 *         - password
 *         - phone
 *       properties:
 *         email:
 *           type: string
 *           description: The email of the user
 *         password:
 *           type: string
 *           description: The password of the user
 *         phone:
 *           type: string
 *           description: The phone number of the user
 *         createdAt:
 *           type: string
 *           description: Date when the user signed up
 *         updatedAt:
 *           type: string
 *           description: Last date of modification
 *       example:
 *         email: olegvragov@gmail.ru
 *         password: $2b$10$ynjb3ZFjZSlD2/Qx3t5LvujeeYKcRhFy0S4/qcCI4HflKqRU58DB.
 *         phone: 0542281408
 *         createdAt: 2024-09-15T11:47:04.584+00:00
 *         updatedAt: 2024-09-15T11:47:04.584+00:00
 */