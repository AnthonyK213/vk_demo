#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vulkan/vulkan_core.h>

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "QueueFamilyIndices.h"
#include "SwapChainSupportDetails.h"
#include "UniformBufferObject.h"
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

  void createDescriptorSetLayout();

  void createGraphicsPipeline();

  void createDepthResources();

  void createFramebuffers();

  void createCommandPool();

  void createTextureImage();

  void createTextureImageView();

  void createTextureSampler();

  void createVertexBuffer();

  void createIndexBuffer();

  void createUniformBuffers();

  void createDescriptorPool();

  void createDescriptorSets();

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

  void updateUniformBuffer(uint32_t currentImage);

  void createImage(uint32_t width, uint32_t height, uint32_t mipLevels,
                   VkFormat format, VkImageTiling tiling,
                   VkImageUsageFlags usage, VkMemoryPropertyFlags properties,
                   VkImage &image, VkDeviceMemory &imageMemory);

  VkCommandBuffer beginSingleTimeCommands();

  void endSingleTimeCommands(VkCommandBuffer commandBuffer);

  void transitionImageLayout(VkImage image, VkFormat format,
                             VkImageLayout oldLayout, VkImageLayout newLayout,
                             uint32_t mipLevels);

  void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
                         uint32_t height);

  VkImageView createImageView(VkImage image, VkFormat format,
                              VkImageAspectFlags aspectFlags,
                              uint32_t mipLevels);

  VkFormat findSupportedFormat(const std::vector<VkFormat> &candidates,
                               VkImageTiling tiling,
                               VkFormatFeatureFlags features);

  VkFormat findDepthFormat();

  void loadModel();

  void generateMipmaps(VkImage image, VkFormat imageFormat, int32_t texWidth,
                       int32_t texHeight, uint32_t mipLevels);

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

  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;
  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;
  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;

  std::vector<VkBuffer> uniformBuffers;
  std::vector<VkDeviceMemory> uniformBuffersMemory;
  std::vector<void *> uniformBuffersMapped;

  VkDescriptorSetLayout descriptorSetLayout;
  VkDescriptorPool descriptorPool;
  std::vector<VkDescriptorSet> descriptorSets;

  uint32_t mipLevels;
  VkImage textureImage;
  VkDeviceMemory textureImageMemory;

  VkImageView textureImageView;

  VkSampler textureSampler;

  VkImage depthImage;
  VkDeviceMemory depthImageMemory;
  VkImageView depthImageView;
};
