// File: NetworkManager.hpp
// Author: Dr. Axel Richter
// Date of Creation: 2024-08-26
// License: MIT License

#ifndef NETWORK_MANAGER_HPP
#define NETWORK_MANAGER_HPP

#include <string>

/**
 * @class NetworkManager
 * @brief Manages network connectivity and communication using WebSockets.
 */
class NetworkManager {
public:
    /**
     * @brief Constructor for NetworkManager.
     * Initializes the network manager with default settings.
     */
    NetworkManager();

    /**
     * @brief Initializes the network interface and prepares for communication.
     */
    void initialize();

    /**
     * @brief Connects to the specified Wi-Fi network.
     * @param ssid The SSID of the Wi-Fi network.
     * @param password The password of the Wi-Fi network.
     */
    void connect(const std::string& ssid, const std::string& password);

    /**
     * @brief Sends a message over the WebSocket connection.
     * @param message The message to be sent.
     */
    void sendMessage(const std::string& message);

private:
    std::string mac_address_;  ///< MAC address of the device.

    /**
     * @brief Fetches the MAC address of the device.
     */
    void fetchMacAddress();
};

#endif // NETWORK_MANAGER_HPP
