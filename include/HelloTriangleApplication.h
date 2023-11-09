#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vulkan/vulkan_core.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <vector>

#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"
#include "Vertex.h"

class HelloTriangleApplication {
public:
  void run();

private:
  void createInstance();

  void createSurface();

  void createLogicalDevice();

  void createSwapChain();

  void createImageViews();

  void createRenderPass();

  void createGraphicsPipeline();

  void createFramebuffers();

  void createCommandPool();

  void createVertexBuffer();

  void createIndexBuffer();

  void createCommandBuffers();

  void createSyncObjects();

private:
  void initWindow();

  void initVulkan();

  void mainLoop();

  void drawFrame();

  void recreateSwapChain();

  void cleanupSwapChain();

  void cleanup();

private:
  static void framebufferResizeCallback(GLFWwindow *window, int width,
                                        int height);

private:
  bool checkValidationLayerSupport();

  bool checkDeviceExtensionSupport(VkPhysicalDevice device);

  std::vector<const char *> getRequiredExtensions();

  void listAvailableExtensions();

  void populateDebugMessengerCreateInfo(
      VkDebugUtilsMessengerCreateInfoEXT &createInfo);

  bool isDeviceSuitable(VkPhysicalDevice device);

  void setupDebugMessenger();

  void pickPhysicalDevice();

  QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

  uint32_t findMemoryType(uint32_t typeFilter,
                          VkMemoryPropertyFlags properties);

  void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
                    VkMemoryPropertyFlags properties, VkBuffer &buffer,
                    VkDeviceMemory &bufferMemory);

  void copyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);

  SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);

  VkSurfaceFormatKHR chooseSwapSurfaceFormat(
      const std::vector<VkSurfaceFormatKHR> &availableFormats);

  VkPresentModeKHR chooseSwapPresentMode(
      const std::vector<VkPresentModeKHR> &availablePresentModes);

  VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR &capabilities);

  VkShaderModule createShaderModule(const std::vector<char> &code);

  void recordCommandBuffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);

public:
  ~HelloTriangleApplication();

private:
  GLFWwindow *window;

  VkInstance instance;
  VkDebugUtilsMessengerEXT debugMessenger;
  VkSurfaceKHR surface;

  VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
  VkDevice device;

  VkQueue graphicsQueue;
  VkQueue presentQueue;

  VkSwapchainKHR swapChain;
  std::vector<VkImage> swapChainImages;
  VkFormat swapChainImageFormat;
  VkExtent2D swapChainExtent;
  std::vector<VkImageView> swapChainImageViews;
  std::vector<VkFramebuffer> swapChainFramebuffers;

  VkRenderPass renderPass;
  VkPipelineLayout pipelineLayout;
  VkPipeline graphicsPipeline;

  VkCommandPool commandPool;
  std::vector<VkCommandBuffer> commandBuffers;

  std::vector<VkSemaphore> imageAvailableSemaphores;
  std::vector<VkSemaphore> renderFinishedSemaphores;
  std::vector<VkFence> inFlightFences;
  uint32_t currentFrame = 0;

  bool framebufferResized = false;

  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;
};
